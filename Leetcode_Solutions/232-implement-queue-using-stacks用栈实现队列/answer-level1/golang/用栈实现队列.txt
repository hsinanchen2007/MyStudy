### 解题思路
一个栈用于push,另一个栈用于Pop和Peek

### 代码

```golang

type MyQueue struct {
	stack1 []int
	stack2 []int
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{
		stack1: make([]int, 0),
		stack2: make([]int, 0),
	}
}

/** Push element x to the back of queue. */
func (queue *MyQueue) Push(x int) {
	queue.stack1 = append(queue.stack1, x)

}

/** Removes the element from in front of queue and returns that element. */
func (queue *MyQueue) Pop() int {
	var top int
	if len(queue.stack2) > 0 {
		l := len(queue.stack2) - 1
		top = queue.stack2[l]
		queue.stack2 = queue.stack2[0:l]

	} else {
		l := len(queue.stack1)
		for l > 0 {
			queue.stack2 = append(queue.stack2, queue.stack1[l-1])
			l--
		}
		queue.stack1 = queue.stack1[:0]

		l = len(queue.stack2) - 1
		top = queue.stack2[l]
		queue.stack2 = queue.stack2[0:l]
	}
	return top
}

/** Get the front element. */
func (queue *MyQueue) Peek() int {
	var top int
	if len(queue.stack2) > 0 {
		l := len(queue.stack2) - 1
		top = queue.stack2[l]

	} else {
		l := len(queue.stack1)
		for l > 0 {
			queue.stack2 = append(queue.stack2, queue.stack1[l-1])
			l--
		}
		queue.stack1 = queue.stack1[:0]

		l = len(queue.stack2) - 1
		top = queue.stack2[l]
	}
	return top
}

/** Returns whether the queue is empty. */
func (queue *MyQueue) Empty() bool {
	return len(queue.stack2) == 0 && len(queue.stack1) == 0
}



```