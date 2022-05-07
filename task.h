#ifndef TASK_H
#define TASK_H

enum STATUS{OVER,RUN};
class TASK
{
public:
    TASK();
    void init(STATUS s);
    virtual void run(){}
    bool over();
    STATUS status;
};

#endif // TASK_H
