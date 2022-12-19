#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

struct ListNode_L
{
	int val;
	struct ListNode_L* last;
	struct ListNode_L* next;
};
typedef struct 
{
    struct ListNode_L *stack_bom;
	struct ListNode_L *stack_top;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() 
{
    /*最大包含3000数的队列*/
	MyQueue *que_p = NULL;

	que_p = (MyQueue *)malloc(sizeof(MyQueue)*1);
	que_p->stack_bom = NULL;
	que_p->stack_top = NULL;

	return que_p;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) 
{	
	if ((obj->stack_bom == obj->stack_top)&&(obj->stack_top == NULL))
	{
		obj->stack_top = (struct ListNode_L *)malloc(sizeof(struct ListNode_L)*1);
		obj->stack_top->val = x;
		obj->stack_top->last = NULL;
		obj->stack_top->next = NULL;
		obj->stack_bom = obj->stack_top;
		return;
	}

	struct ListNode_L *now_n = NULL;
	now_n = obj->stack_top;
	now_n->next = (struct ListNode_L *)malloc(sizeof(struct ListNode_L)*1);
	obj->stack_top = now_n->next;
	obj->stack_top->last = now_n;
	obj->stack_top->next = NULL;
	obj->stack_top->val  = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) 
{
	if (obj->stack_bom == NULL)
	{
		printf("No Element return a valid value 0x7fffffff !");
		return 0x7fffffff;
	}

	int res = 0;
	struct ListNode_L *del = NULL;

	del = obj->stack_bom;
	res = del->val;
	obj->stack_bom = obj->stack_bom->next;
	if (obj->stack_bom != NULL)
	{
		obj->stack_bom->last = NULL;
	}
	else
	{
		obj->stack_top = obj->stack_bom;
	}
	free(del);
	return res;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) 
{
	if (obj->stack_bom == NULL)
	{
		printf("No Element return a valid value 0x7fffffff !");
		return 0x7fffffff;
	}

	int res = 0;

	res = obj->stack_bom->val;
	return res;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) 
{
	if ((obj->stack_bom == NULL)&&(obj->stack_top == NULL))
	{
		return true;
	}
	return false;
}

void myQueueFree(MyQueue* obj) 
{
	struct ListNode_L *f_node = NULL;

	while (obj->stack_bom != NULL)
	{
		f_node = obj->stack_bom;
		obj->stack_bom = obj->stack_bom->next;
		free(f_node);
	}
	free(obj);
}
