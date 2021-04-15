//Nome: Rodrigo Limongi De Martini
//TIA: 32021852

#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__

#include "StaticStack.h"

namespace Queue
{
	const int STATIC_QUEUE_CAPACITY = Stack::STATIC_STACK_CAPACITY;

	struct StaticQueue
	{
		int count;

		Stack::StaticStack stack1;
		Stack::StaticStack stack2;
	};

	StaticQueue Create();

	bool Enqueue(StaticQueue &queue, char elem);

	char Dequeue(StaticQueue &queue);

	char Front(StaticQueue &queue);

	int Size(const StaticQueue &queue);

	int Count(const StaticQueue &queue);

	bool IsEmpty(const StaticQueue &queue);

	bool Clear(StaticQueue &queue);

}

#endif // __STATIC_QUEUE_H__
