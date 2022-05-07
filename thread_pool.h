#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <list>
#include "thread_data.h"
using std::list;
const int thread_numbers_c = 10;
class TASK;
class THREAD_POOL
{
public:
    THREAD_POOL();
    ~THREAD_POOL();
    bool init();
    void set_task(TASK* t);

private:
    pthread_mutex_t mutex;
    list<THREAD_DATA*> ths;

};

#endif // THREAD_POOL_H
