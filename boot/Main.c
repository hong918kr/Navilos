#include "stdint.h"

void main(void)
{
    uint32_t* dummyAddr = (uint32_t*)(1024*1024*1024);
    *dummyAddr = sizeof(long);
}
