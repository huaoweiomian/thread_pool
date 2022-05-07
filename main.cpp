//#include <QCoreApplication>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <list>
using std::list;
//#include <QDebug>
void* func(void *arg){
        //qDebug("hello world");
    //sleep(3);
    printf("hello world\n");
    return NULL;
}
void p(list<int>& arg){
    for(auto v : arg){
        printf("%d ",v);
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
//    pthread_t thread_id;
//    pthread_cond_t cond;
//    pthread_cond_init(&cond,NULL);
//    pthread_cond_signal(&cond);
//    pthread_mutex_t mutex;
//    pthread_mutex_init(&mutex,NULL);
//    pthread_cond_wait(&cond, &mutex);
    //pthread_join(thread_id, NULL);
    list<int> tmp;
    for(int i = 0; i< 10; ++i)
        tmp.push_back(i);
    p(tmp);
    int i = 4;
    for(auto it = tmp.begin(); it != tmp.end(); it++){
        if(i > *it)
            continue;
        tmp.insert(it,i);
        break;
    }
    p(tmp);
    printf("hello world\n");
    getchar();
    return 0;
    //return a.exec();
}
