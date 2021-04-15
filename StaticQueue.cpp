//Nome: Rodrigo Limongi De Martini
//TIA: 32021852

#include "StaticQueue.h"
#include "StaticStack.h"

namespace Queue
{

	StaticQueue Create()
	{
		StaticQueue queue = { 0,  Stack::Create(), Stack::Create()};

		return queue;
	}

	bool Enqueue(StaticQueue& queue, char elem)
	{
		if (queue.count == Size(queue))
		{
			return false;
		}

		Stack::Push(queue.stack1, elem);

		++queue.count;

		return true;
	}

	char Dequeue(StaticQueue& queue)
	{
		if (IsEmpty(queue))
		{
			return '\0';
		}
        else
        {
            while(!Stack::IsEmpty(queue.stack1))
            {
                char elem = Stack::Pop(queue.stack1);
                Stack::Push(queue.stack2, elem);
            }

            char value = Stack::Pop(queue.stack2);

            while(!Stack::IsEmpty(queue.stack2))
            {
                char elem = Stack::Pop(queue.stack2);
                Stack::Push(queue.stack1, elem);
            }

            --queue.count;

            return value;
        }
	}

	char Front(StaticQueue& queue)
	{
	    if (IsEmpty(queue))
        {
            return '\0';
        }
        else
        {
            while(!Stack::IsEmpty(queue.stack1))
            {
                char elem = Stack::Pop(queue.stack1);
                Stack::Push(queue.stack2, elem);
            }

            char value = Stack::Top(queue.stack2);

            while(!Stack::IsEmpty(queue.stack2))
            {
                char elem = Stack::Pop(queue.stack2);
                Stack::Push(queue.stack1, elem);
            }

            return value;
        }
	}

	int Size(const StaticQueue& queue)
	{
		return Stack::Size(queue.stack1);
	}

	int Count(const StaticQueue& queue)
	{
		return queue.count;
	}

	bool IsEmpty(const StaticQueue& queue)
	{
		return queue.count == 0;
	}

	bool Clear(StaticQueue& queue)
	{
		while (!IsEmpty(queue))
		{
			Dequeue(queue);
		}

		return IsEmpty(queue);
	}

}

