#ifndef THREAD_DATA_H
#define THREAD_DATA_H

#include <pthread.h>
#include "task.h"
#include <list>
using std::list;
class THREAD_DATA
{
public:
    THREAD_DATA();
    ~THREAD_DATA();
    bool init();
    void run();
    void start(TASK* t);
    void over();
    int task_size();
private:
    list<TASK*> ts;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    pthread_mutex_t mutex_cond;
    pthread_t thread_id;
};

#endif // THREAD_DATA_H
