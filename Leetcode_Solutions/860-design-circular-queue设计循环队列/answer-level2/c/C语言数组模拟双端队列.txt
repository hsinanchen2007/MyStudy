### 解题思路

> 参考自 https://leetcode-cn.com/problems/design-circular-queue/solution/shu-zu-shi-xian-de-xun-huan-dui-lie-by-liweiwei141/ 

这题需要你把后面检查队列是空还是满的函数，也就是myCircularQueueIsFull， myCircularQueueIsEmpyt移动到前面 ，或者先在前面定义，否则会编译报错。（我以为官方会把这些函数先搞一个全局定义的）

因为用数组进行模拟，因此需要额外当head和tail到数组最后一位的时候，再前进就需要回到最前面。也就是

- head = (head + 1) / size
- tail = (tail + 1) / size

tail始终在最后一个元素的后一位，这样子验证数组为空，就是head=tail, 也就是留出一个额外空间


### 代码

```c
typedef struct {
	int *arr;
	int size;
	int head;
	int tail;

} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue *obj = malloc(sizeof(MyCircularQueue));
	obj->arr = malloc(sizeof(int) * (k+1));
	obj->head = 0;
	obj->tail = 0;
	obj->size = k + 1;
	return obj;

}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return ( obj->head == obj->tail) ? true : false;

}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {

	return (obj->head == (obj->tail+1) % obj->size) ? true :false;

}


/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

	if  (myCircularQueueIsFull(obj)) return false;

	obj->arr[obj->tail] = value;

    obj->tail = (obj->tail + 1) % obj->size;

	return true;


}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {

	if  (myCircularQueueIsEmpty(obj)) return false;

	obj->head = (obj->head + 1) % obj->size;

	return true;

}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {

    if  (myCircularQueueIsEmpty(obj)) return -1;


	return obj->arr[obj->head];

}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if  (myCircularQueueIsEmpty(obj)) return -1;
	int pos = (obj->tail+obj->size-1) % obj->size;
	return obj->arr[pos];


}



void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->arr);
	free(obj);

}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
```