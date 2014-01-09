/********************  HEADERS  *********************/
#include <cstdio>
#include <cassert>
#include <cstring>
#include <execinfo.h>
#include "SimpleCallStack.h"

#define CALL_STACK_DEFAULT_SIZE 32
#define CALL_STACK_GROW_THRESHOLD 1024

/*******************  FUNCTION  *********************/
SimpleCallStack::SimpleCallStack(void)
	:Stack(STACK_ORDER_ASC)
{
}

/*******************  FUNCTION  *********************/
void SimpleCallStack::loadCurrentStack(void)
{
	if (this->stack == NULL)
		this->grow();
	
	//try to load in current buffer, if not realloc and retry
	bool retry;
	do {
		//try to load with current buffer
		int loadedSize = backtrace(this->stack,this->memSize);
		assert(loadedSize <= this->memSize);
		assert(loadedSize > 0);

		//miss some entries, need to grow the buffer
		if (loadedSize == this->memSize)
		{
			this->grow();
			retry = true;
		} else {
			this->size = loadedSize;
			retry = false;
		}
	} while(retry);
}
