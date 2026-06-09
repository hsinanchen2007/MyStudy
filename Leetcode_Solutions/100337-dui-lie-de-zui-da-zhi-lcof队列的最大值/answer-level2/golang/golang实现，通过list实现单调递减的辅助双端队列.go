golang实现，通过list实现单调递减的辅助双端队列

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 当一个新元素入队的时候，在该元素出队之前，它前面所有连续的比它小的元素将不会再对队列的最大值产生影响．
// 维护一个单调递减的辅助双端队列，新元素入队前，将辅助队列对尾所有连续的比它小的元素删除后，再将新元素入队
// 辅助队列的队首元素为当前最大值元素

type MaxQueue struct {
	t_q *list.List  // 辅助双向链表，每次插入节点时，需维护该队列单调递减，该队列的队首元素为当前最大值元素
	m_q *list.List  // 实现的 MaxQueue
}

func Constructor() MaxQueue {

	return MaxQueue{t_q: list.New(), m_q: list.New()}
}

func (this *MaxQueue) Max_value() int {
	if this.t_q.Len()==0 {
		return -1
	}

	return this.t_q.Front().Value.(int)
}

func (this *MaxQueue) Push_back(value int)  {
	this.m_q.PushBack(value)
	var pre *list.Element
	for e:=this.t_q.Back(); e!=nil && e.Value.(int)<value; e=pre {
		pre = e.Prev()  // 删除该节点前，先记录该节点的前驱节点
		this.t_q.Remove(e)
	} 

	this.t_q.PushBack(value)
}

func (this *MaxQueue) Pop_front() int {
	if this.m_q.Len()==0 {
		return -1
	}

	m_e := this.m_q.Front()
	t_e := this.t_q.Front()

	if t_e.Value.(int)==m_e.Value.(int) {
		this.t_q.Remove(t_e)
	}

	this.m_q.Remove(m_e)
	return m_e.Value.(int)
}
```
