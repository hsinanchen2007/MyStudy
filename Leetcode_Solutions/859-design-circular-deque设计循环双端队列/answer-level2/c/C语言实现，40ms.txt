### 解题思路

难得一题，写完提交就通过了，开心呢！

几个注意点：

- 多申请一个位置用于判断是否队列已满。
- 添加，删除元素时注意边界判断

### 代码

```c
typedef struct {
	int *arr;
	int head;
	int tail;
	int size;

} MyCircularDeque;
bool myCircularDequeIsFull(MyCircularDeque* obj) ;
bool myCircularDequeIsEmpty(MyCircularDeque* obj) ;
/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {

	MyCircularDeque *obj = malloc(sizeof(MyCircularDeque) * (k+1));
	obj->arr = malloc(sizeof(int) * (k+1));
	obj->head = 0;
	obj->tail = 0;
	obj->size = k + 1;
	return obj;

}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {

	if ( myCircularDequeIsFull(obj)) return false;

	int pos = (obj->head+obj->size-1) % obj->size;
	obj->arr[pos] = value;
	obj->head = pos;
	return true;


}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
	if ( myCircularDequeIsFull(obj)) return false;

	obj->arr[obj->tail] = value;
	obj->tail = (obj->tail+1) % obj->size;

	return true;

}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
	if ( myCircularDequeIsEmpty(obj)) return false;

	obj->head = (obj->head+1) % obj->size;
	return true;

}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
	if ( myCircularDequeIsEmpty(obj)) return false;

	obj->tail = (obj->tail-1+obj->size) % obj->size;
	return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
	if ( myCircularDequeIsEmpty(obj) ) return -1;

	return obj->arr[obj->head];

}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
	if ( myCircularDequeIsEmpty(obj) ) return -1;

	int pos = (obj->tail+obj->size-1) % obj->size;

	return obj->arr[pos];


}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {

	return (obj->head == obj->tail) ? true : false;

}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {

	return (obj->head == (obj->tail+1) % obj->size) ? true : false;

}

void myCircularDequeFree(MyCircularDeque* obj) {
	free(obj->arr);
	free(obj);
	return ;

}
```