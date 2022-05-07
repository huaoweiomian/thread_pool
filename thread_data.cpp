#include "thread_data.h"

static void* func(void* arg){
    THREAD_DATA* td = (THREAD_DATA*)arg;
    td->run();
    return NULL;
}
THREAD_DATA::THREAD_DATA()
{

}

THREAD_DATA::~THREAD_DATA()
{
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&mutex_cond);
    pthread_cond_destroy(&cond);
}

bool THREAD_DATA::init()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex_cond, NULL);
    pthread_cond_init(&cond, NULL);


    //int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
    //int pthread_mutex_destroy(pthread_mutex_t *mutex);
    //int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);
    //int pthread_cond_destroy(pthread_cond_t *cond);

    //int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
    pthread_create(&thread_id, NULL, func,this);
    return true;
}

void THREAD_DATA::run()
{
    while (true) {
        if(ts.empty())
            pthread_cond_wait(&cond, &mutex_cond);
        pthread_mutex_lock(&mutex);
        TASK* t = *ts.begin();
        ts.pop_front();
        pthread_mutex_unlock(&mutex);
        if(t->over())
            return;
        t->run();
    }
}

void THREAD_DATA::start(TASK *t)
{
    ts.push_back(t);
    pthread_cond_signal(&cond);
}

int THREAD_DATA::task_size()
{
    return (int)ts.size();
}

