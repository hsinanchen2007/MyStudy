### 解题思路
主要思想：用2个队列模拟栈

### 代码

```golang
// golang没有队列所以需要先定义队列的操作
type Queue struct {
    Arr []int
}

// 添加队列
func (this *Queue) add(x int) {
    this.Arr=append(this.Arr,x)
}
// 弹出队列
func (this *Queue) pop() int {
    value := this.Arr[0]
    this.Arr=this.Arr[1:]
    return value
}
// 取队列首元素
func (this *Queue) peek() int {
    return this.Arr[0]
}
// 判断队列是否为空
func (this *Queue) isEmpty() bool {
    return len(this.Arr)==0
}
// 创建栈类型，用q1、q2两个队列进行模拟
type MyStack struct {
    q1 *Queue
    q2 *Queue
}


/** Initialize your data structure here. */
// 初始化栈，将2个队列都置空
func Constructor() MyStack {
    myStack := MyStack{}
    Q1 := new(Queue)
    Q1.Arr=[]int{}
    myStack.q1=Q1
    Q2 := new(Queue)
    Q2.Arr=[]int{}
    myStack.q2=Q2

    return myStack
}


/** Push element x onto stack. */
// 压栈操作，判断哪个队列不为空，则添加到哪个队列，如果都为空，则添加到q1队列
func (this *MyStack) Push(x int)  {
    if !this.q1.isEmpty() {
        this.q1.add(x)
    } else if !this.q2.isEmpty() {
        this.q2.add(x)
    } else {
        this.q1.add(x)
    }
}


/** Removes the element on top of the stack and returns that element. */
// 出栈操作，判断哪个队列不为空，则依次取该队列头元素，加入到另一个队列，当取到最后一个元素时，返回该元素的值，且该元素不加入另一个队列
func (this *MyStack) Pop() int {
    if !this.q1.isEmpty() {
        for !this.q1.isEmpty() {
            cur := this.q1.pop()
            if this.q1.isEmpty() {
                return cur
            }
            this.q2.add(cur)
        }
    } else {
        for !this.q2.isEmpty() {
            cur := this.q2.pop()
            if this.q2.isEmpty() {
                return cur
            }
            this.q1.add(cur)
        }
    }

    return -1
}


/** Get the top element. */
// 取栈顶操作，判断哪个队列不为空，则依次取该队列头元素，加入到另一个队列，返回原队列最后一个元素的值
func (this *MyStack) Top() int {
    if !this.q1.isEmpty() {
        for !this.q1.isEmpty() {
            cur := this.q1.pop()
            this.q2.add(cur)
            if this.q1.isEmpty() {
                return cur
            }
        }
    } else {
        for !this.q2.isEmpty() {
            cur := this.q2.pop()
            this.q1.add(cur)
            if this.q2.isEmpty() {
                return cur
            }
        }
    }

    return -1
}


/** Returns whether the stack is empty. */
// 判断栈是否为空等于判断2个队列是否都为空
func (this *MyStack) Empty() bool {
    return this.q1.isEmpty() && this.q2.isEmpty()
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