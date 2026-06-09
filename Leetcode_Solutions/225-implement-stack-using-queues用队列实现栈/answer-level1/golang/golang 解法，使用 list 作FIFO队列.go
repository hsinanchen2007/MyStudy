golang 解法，使用list作FIFO队列

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)

1. 利用两个队列

```
// 使用GO中的list作为FIFO队列, 利用两个队列实现栈
// "push()"，"pop()"，"top()"，"empty()"的时间复杂度分别为：O(1),O(n),O(1),O(1)

type MyStack struct {
	q1 *list.List
	q2 *list.List
	topElement int
}

func Constructor() MyStack {

	return MyStack{q1:list.New(), q2:list.New(), topElement:-1}
}

func (this *MyStack) Push(x int)  {

	this.q1.PushBack(x)
	this.topElement = x
}

func (this *MyStack) Pop() int {

	if this.q1.Len()==0 {
		return -1
	}

	for this.q1.Len()>1 {
		e := this.q1.Front()
		this.q1.Remove(e)
		this.q2.PushBack(e.Value.(int))
		this.topElement = e.Value.(int)
	}

	x := this.q1.Front()
	this.q1.Remove(x)
	this.q1, this.q2 = this.q2, this.q1
	if this.q1.Len() == 0 {
		this.topElement = -1
	}
	
	return x.Value.(int) 	
}

func (this *MyStack) Top() int {

	return this.topElement
}

func (this *MyStack) Empty() bool {

	return this.q1.Len()==0
}

```

2. 利用一个队列

```
// 使用GO中的list作为FIFO队列, 利用一个队列实现栈,每次push时都将新入队的元素移到队首
// "push()"，"pop()"，"top()"，"empty()"的时间复杂度分别为：O(n),O(1),O(1),O(1)

type MyStack struct {
	q *list.List
}

func Constructor() MyStack {

	return MyStack{q:list.New()}
}

func (this *MyStack) Push(x int)  {

	this.q.PushBack(x)
	for i:=0; i<this.q.Len()-1; i++ {
		e := this.q.Front()
		this.q.Remove(e)
		this.q.PushBack(e.Value.(int))
	}
}

func (this *MyStack) Pop() int {

	if this.q.Len()==0 {
		return -1
	}

	e := this.q.Front()
	this.q.Remove(e)

	return e.Value.(int)	
}

func (this *MyStack) Top() int {

	if this.q.Len()==0 {
		return -1
	}

	e := this.q.Front()
	return e.Value.(int)
}

func (this *MyStack) Empty() bool {

	return this.q.Len()==0
}
```

