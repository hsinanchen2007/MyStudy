typedef struct MyQueue_t{
	int  val;
	struct MyQueue_t* next;
}MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
	MyQueue* myList = (MyQueue*)malloc(sizeof(MyQueue));
	if (myList == NULL)
		printf("malloc error\n");
	else
		myList->next = NULL;
		myList->val = 0;
	
	return myList;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	MyQueue* head = obj;
	while (head->next != NULL)
		head = head->next;

	MyQueue* newNode = (MyQueue*)malloc(sizeof(MyQueue));
	if (newNode == NULL) {
		printf("malloc error\n");
	}
	else {
		newNode->next = NULL;
		newNode->val = x;
	}
    
    head->next = newNode;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	MyQueue* head = obj;
	MyQueue* p = head->next;
	int num = p->val;

	head->next = p->next;
	free(p);

	return num;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	MyQueue* head = obj;
	MyQueue* p = head->next;
	int num = p->val;

	return num;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (obj->next == NULL)
		return true;
	else
		return false;
}

void myQueueFree(MyQueue* obj) {
	while (myQueueEmpty == false) {
		myQueuePop(obj);
	}
}