#include "task.h"

TASK::TASK()
{
    status = RUN;
}

void TASK::init(STATUS s)
{
    status = s;
}

bool TASK::over()
{
    return status == OVER;
}
