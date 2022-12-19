![image.png](https://pic.leetcode-cn.com/f6639a3fdc3de492b3a8173fd72906c4d1c084f1fe3ecc546676ab95bc5d749f-image.png)

```
type Stack struct {
    v []int
}

func (this *Stack) Push(x int) {
    this.v = append(this.v, x)
}

func (this *Stack) Pop() int {
    pv := this.Peek()
    this.v = this.v[:len(this.v) - 1]
    
    return pv
}

func (this *Stack) Peek() int {
    return this.v[len(this.v) - 1]
}

func (this *Stack) Empty() bool{
    return len(this.v) == 0
}

type MyQueue struct {
    s1 Stack
    s2 Stack
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
    return MyQueue{
        s1: Stack{},
        s2: Stack{},
    }
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
    this.s2.Push(x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
    this.toS1()

    return this.s1.Pop()
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
    this.toS1()
    
    return this.s1.Peek()
}

/** Copy data to stack 1 if s1 is empty */
func (this *MyQueue) toS1() {
    if this.s1.Empty() && !this.s2.Empty() {
        for !this.s2.Empty() {
            this.s1.Push(this.s2.Pop())
        }
    }
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
    return this.s1.Empty() && this.s2.Empty()
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
```
