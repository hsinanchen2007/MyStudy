### 解题思路
双端队列设计的核心：
1.front和rear都初始化为0，
2.队列为空：front == rear，队列满：(rear+1)%maxSize == front;
3.队列为满时，数组需要空出一个空间，原因是队列为满时front不能等于rear


[个人博客地址](http://47.101.136.180/)

### 代码

```java
class MyCircularDeque {

	int[] arr;
	// 初始化这两个指针都为0
	int rear = 0;
	int front = 0;
	int maxSize;

	/**
	 * Initialize your data structure here. Set the size of the deque to be k.
	 */
	public MyCircularDeque(int k) {
		//需要空出一个空间
		maxSize = k + 1;
		arr = new int[k + 1];

	}

	/**
	 * Adds an item at the front of Deque. Return true if the operation is
	 * successful.
	 */
	public boolean insertFront(int value) {
		if (isFull()) {
			return false;
		}
		front = (front - 1 + maxSize) % maxSize;
		arr[front] = value;
		return true;
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
    	if (isFull()) {
    		return false;
    	}
    	arr[rear] = value;
    	rear = (rear+1) % maxSize;
    	return true;
    }

	/**
	 * Deletes an item from the front of Deque. Return true if the operation is
	 * successful.
	 */
	public boolean deleteFront() {
		if (isEmpty()) {
			return false;
		}
		front = (front+1) % maxSize;
		return true;
	}

	/**
	 * Deletes an item from the rear of Deque. Return true if the operation is
	 * successful.
	 */
	public boolean deleteLast() {
		if (isEmpty()) {
			return false;
		}
		rear = (rear - 1 + maxSize) % maxSize;
		return true;
	}

	/** Get the front item from the deque. */
	public int getFront() {
		if (isEmpty()) {
			return -1;
		}
		return arr[front];
	}

	/** Get the last item from the deque. */
	public int getRear() {
		if (isEmpty()) {
			return -1;
		}
		return arr[(rear - 1 + maxSize) % maxSize];
	}

	/** Checks whether the circular deque is empty or not. */
	public boolean isEmpty() {
		return rear == front;
	}

	/** Checks whether the circular deque is full or not. */
	public boolean isFull() {
		return (rear + 1) % maxSize == front;
	}
}
```