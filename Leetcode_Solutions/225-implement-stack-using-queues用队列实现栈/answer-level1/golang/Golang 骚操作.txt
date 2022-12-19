
### 方法 1，用 slice 模拟

```golang

type MyQueue struct {
    arr []interface{}
}

// Golang 没有队列啊 还得先 mock shift 和 unshift

// 最前面的出队
func (this *MyQueue) shift() interface{} {
    var x interface{}
    x, this.arr = this.arr[0], this.arr[1:]
    return x
}

// 入队加到末尾
func (this *MyQueue) unshift(x interface{}) {
    this.arr = append(this.arr, x)
}

type MyStack struct {
    queue MyQueue
}



/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{queue: MyQueue{arr: []interface{}{}}}
}


/** Push element x onto stack. */
// 入栈在末尾
func (this *MyStack) Push(x int)  {
    this.queue.unshift(x)
}


/** Removes the element on top of the stack and returns that element. */
// 末尾一个出栈
func (this *MyStack) Pop() int {
    queue := MyQueue{}
    length := len(this.queue.arr)
    lastElement := this.queue.arr[length - 1]
    for i := 0; i <= length - 2; i++ {
        queue.unshift(this.queue.arr[i])
    }
    this.queue = queue
    return lastElement.(int)

}


/** Get the top element. */
func (this *MyStack) Top() int {
    length := len(this.queue.arr)
    return this.queue.arr[length - 1].(int)
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    length := len(this.queue.arr)
    return length == 0
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */

```

### 方法2 用 list 模拟（双端链表）

```golang
import "container/list"

type MyQueue2 struct {
    l *list.List
}

// Golang 没有队列啊 还得先 mock shift 和 unshift

// 最前面的出队
func (this *MyQueue2) Shift() *list.Element {
   elem := this.l.Front()
   this.l.Remove(elem)
   return elem
}

// 入队加到末尾
func (this *MyQueue2) Unshift(x interface{}) {
    this.l.PushBack(x)
}

func (this *MyQueue2) Len() int {
    return this.l.Len()
}

func (this *MyQueue2) Last() *list.Element {
    return this.l.Back()
}

func (this *MyQueue2) First() *list.Element {
    return this.l.Front()
}

type MyStack struct {
    queue MyQueue2
}



/** Initialize your data structure here. */
func Constructor() MyStack {
    l := list.New()
    return MyStack{queue: MyQueue2{l: l}}
}


/** Push element x onto stack. */
// 入栈在末尾
func (this *MyStack) Push(x int)  {
    this.queue.Unshift(x)
}


/** Removes the element on top of the stack and returns that element. */
// 末尾一个出栈
func (this *MyStack) Pop() int {
    queue := MyQueue2{l: list.New()}
    lastElement := this.queue.Last()
    ptr := this.queue.First()
    for ptr != lastElement {
        queue.Unshift(ptr.Value)
        ptr = ptr.Next()
    }
    this.queue = queue
    return lastElement.Value.(int)
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.queue.Last().Value.(int)
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return this.queue.Len() == 0
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */


```