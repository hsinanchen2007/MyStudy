### 解题思路
循环数组

### 代码

```golang

//	641
type MyCircularDeque struct {
	data  []int
	front int
	rear  int
	cap   int
}

/** Initialize your data structure here. Set the size of the deque to be k. */
func Constructor(k int) MyCircularDeque {
	return MyCircularDeque{
		data:  make([]int, k+1),
		front: 0,
		rear:  0,
		cap:   k + 1,
	}
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
func (mcd *MyCircularDeque) InsertFront(value int) bool {
	if mcd.IsFull() {
		return false
	}
	mcd.front--
	if mcd.front < 0 {
		mcd.front = mcd.cap - 1
	}
	mcd.data[mcd.front] = value
	return true
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
func (mcd *MyCircularDeque) InsertLast(value int) bool {
	if mcd.IsFull() {
		return false
	}
	mcd.data[mcd.rear] = value
	mcd.rear++
	if mcd.rear == mcd.cap {
		mcd.rear = 0
	}
	return true
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
func (mcd *MyCircularDeque) DeleteFront() bool {
	if mcd.IsEmpty() {
		return false
	}
	mcd.front++
	if mcd.front == mcd.cap {
		mcd.front = 0
	}
	return true
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
func (mcd *MyCircularDeque) DeleteLast() bool {
	if mcd.IsEmpty() {
		return false
	}
	mcd.rear--
	if mcd.rear == -1 {
		mcd.rear = mcd.cap - 1
	}
	return true
}

/** Get the front item from the deque. */
func (mcd *MyCircularDeque) GetFront() int {
	if mcd.IsEmpty() {
		return -1
	}
	return mcd.data[mcd.front]
}

/** Get the last item from the deque. */
func (mcd *MyCircularDeque) GetRear() int {
	if mcd.IsEmpty() {
		return -1
	}
	if mcd.rear == 0 {
		return mcd.data[mcd.cap-1]
	}
	return mcd.data[mcd.rear-1]
}

/** Checks whether the circular deque is empty or not. */
func (mcd *MyCircularDeque) IsEmpty() bool {
	return mcd.rear == mcd.front
}

/** Checks whether the circular deque is full or not. */
func (mcd *MyCircularDeque) IsFull() bool {
	rear := mcd.rear + 1
	if rear == mcd.cap {
		rear = 0
	}
	return rear == mcd.front
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.InsertFront(value);
 * param_2 := obj.InsertLast(value);
 * param_3 := obj.DeleteFront();
 * param_4 := obj.DeleteLast();
 * param_5 := obj.GetFront();
 * param_6 := obj.GetRear();
 * param_7 := obj.IsEmpty();
 * param_8 := obj.IsFull();
 */

```