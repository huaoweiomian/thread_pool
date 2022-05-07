#include "thread_pool.h"

THREAD_POOL::THREAD_POOL()
{

}

THREAD_POOL::~THREAD_POOL()
{
    pthread_mutex_destroy(&mutex);
}

bool THREAD_POOL::init()
{
    pthread_mutex_init(&mutex,NULL);
    for(int i = 0 ; i < thread_numbers_c; ++i){
        THREAD_DATA* td = new THREAD_DATA();
        if(!td->init())
            return false;
        ths.push_back(td);
    }
    return true;
}

void THREAD_POOL::set_task(TASK *t)
{
    pthread_mutex_lock(&mutex);
    THREAD_DATA* ts = *ths.begin();
    ths.pop_front();
    ts->start(t);
    for(auto it = ths.begin(); it != ths.end(); it++){
        if(ts->task_size() > (*it)->task_size())
            continue;
        ths.insert(it, ts);
        break;
    }
    pthread_mutex_unlock(&mutex);
}
