### 解题思路
go语言不含有队列栈结构，可以用列表模拟队列。只是单纯的应付笔试，实际工程中使用会造成内存泄漏！

### 代码

```golang
type MyStack struct {
    q queue
}

//定义一个队列
type queue struct{
    nums []int
}

func (q *queue)front()(int){
    if len(q.nums) == 0{
        return 0;
    }
    return q.nums[0]
}

func (q *queue)pop()(int){
    top := q.nums[0]
    q.nums = q.nums[1:]
    return top
}

func (q *queue)push(x int){
    q.nums = append(q.nums,x)
}

func (q *queue)empty()bool{

    if len(q.nums) != 0{
        return false
    }else{
        return true
    }
}

/** Initialize your data structure here. */
func Constructor() MyStack {
    stack := new(MyStack)
    return *stack
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.q.push(x)
    
    for i:=1;i<len(this.q.nums);i++{
        this.q.push(this.q.front())
        this.q.pop()
    }
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    return this.q.pop()
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.q.front()
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return this.q.empty()
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