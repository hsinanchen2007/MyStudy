### 解题思路

- 解法1. 使用两个队列加一个top变量。 top记录q1的队尾，每次pop数据时现将q1的前n-1个倒到q2去，再把top出队
- 解法2. 使用两个队列，q2队头存栈顶元素，每次push时新元素就是新的栈顶元素。先将q2前面的数据倒到q1去，再压新栈顶（这时新栈顶依旧是q2队头），再将q1的元素倒回q2
- ps: 上面两种都是借助两个队列实现的栈，在元素倒来倒去的过程可以用队列替换来代替入队出队操作，降低复杂度
- 解法3. 使用一个队列。每次入队时将前面所有元素依次出队并重新入队到队尾

### 代码

```golang
// 使用一个队列

type MyStack struct {
    queue *list.List
}

func Constructor() MyStack {
    return MyStack{
        queue: list.New(),
    }
}

// 压栈
func (this *MyStack) Push(x int) {

    // 先将新栈顶压入
    this.queue.PushBack(x)
    // 再将前边的元素取出追加到后面
    size := this.queue.Len()
    for size > 1 {  // 由于新加了一个元素，所以是size-1次
        this.queue.PushBack(this.queue.Remove(this.queue.Front()))
        size--
    }
}

// 出栈
func (this *MyStack) Pop() int {
    return this.queue.Remove(this.queue.Front()).(int)
}

// 栈顶
func (this *MyStack) Top() int {
    return this.queue.Front().Value.(int)
}

// 判空
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