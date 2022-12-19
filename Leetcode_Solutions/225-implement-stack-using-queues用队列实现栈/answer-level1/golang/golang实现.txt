方法1：用两个队列, 一个专门push, 另一个pop.
        push() : 先放到push队列里, 然后把之前进来的从pop中取出, 再放到push队列里面, 然后交换引用
        pop () : 从pop中直接弹出
```
// 执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
// 内存消耗 :2 MB, 在所有 Go 提交中击败了100.00%的用户
type Queue []int

func (q *Queue) offer(x int) {
    *q = append(*q, x)
}

func (q *Queue) poll() int {
    r := (*q)[0]
    *q = (*q)[1:]
    return r
}

func (q *Queue) peek() int {
    return (*q)[0]
}

type MyStack struct {
    push *Queue
    pop  *Queue
}


func Constructor() MyStack {
    return MyStack{
        push : &Queue{},
        pop  : &Queue{},
    }
}


// O(n)
func (this *MyStack) Push(x int)  {
    this.push.offer(x)
    // 把之前的放到新加入的后面
    for len(*this.pop) != 0 {
        this.push.offer(this.pop.poll())
    }
    // 交换引用
    *this.push, *this.pop = *this.pop, *this.push
}


func (this *MyStack) Pop() int {
    return this.pop.poll()
}


func (this *MyStack) Top() int {
    return this.pop.peek()
}


func (this *MyStack) Empty() bool {
    return len(*this.pop) == 0
}
```
方法2 : 原理和方法1一样, 只不过一个队列就可以了
```
type Queue []int

func (q *Queue) offer(x int) {
    *q = append(*q, x)
}

func (q *Queue) poll() int {
    r := (*q)[0]
    *q = (*q)[1:]
    return r
}

func (q *Queue) peek() int {
    return (*q)[0]
}

// 栈的实质就是让后来的先出去, 所以让之前来的重新排到后来的后面就可以了, 一个队列就足够了
type MyStack struct {
    q *Queue
}


func Constructor() MyStack {
    return MyStack{ q : &Queue{} }
}


// O(n)
func (this *MyStack) Push(x int)  {    
    this.q.offer(x)
    n := len(*this.q)
    // 把之前的放到新加入的后面
    for n != 1 {
        this.q.offer(this.q.poll())
        n--
    }
}


func (this *MyStack) Pop() int {
    return this.q.poll()
}


func (this *MyStack) Top() int {
    return this.q.peek()
}


func (this *MyStack) Empty() bool {
    return len(*this.q) == 0
}
```



