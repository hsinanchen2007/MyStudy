这题使用链表就可以很简单的解决 时间空间复杂度都可以接受
插入和删除都是 o(n)

首先需要考虑的点有
- 新的位置需要放在两个已知点之间，如何求出这个点。因为要距离最大化，那么肯定是在中点，如果距离是奇数，那就是中点，如果是偶数，那就直接放在左侧。
- 如果要插入到头或者尾，需要特殊判断距离
- 在找到最大距离的同时，需要将对应的插入位置也保存下来

删除的时候只要遍历链表删除即可
具体见注释
```
type ExamRoom struct {
	seat *list.List // 表示坐着的同学的位置
	n    int
}

func Constructor(N int) ExamRoom {
	return ExamRoom{
		seat: list.New(),
		n:    N - 1,
	}
}

func (this *ExamRoom) Seat() int {
    // 还没有人入座，直接将0插入
	if this.seat.Len() == 0 {
		this.seat.PushFront(0)
		return 0
	}
	e := this.seat.Front()
	pre := e.Value.(int)
	max := pre // 头部需要特殊判断
	addVal := 0
	addFront := e
	e = e.Next()
	for ; e != nil; e = e.Next() {
		val := e.Value.(int)
		distant := (val - pre) / 2 // 两点之间的最远距离
		if distant > max {
			max = distant
			addFront = e // 需要插入的点的后一个元素。方便找到后直接插入
			addVal = pre + distant // 需要插入的位置
		}
		pre = val
	}
	distant := this.n - pre // 尾部特殊判断
	if distant > max {
		this.seat.PushBack(this.n) // 直接插入到链表尾部
		return this.n
	}
	this.seat.InsertBefore(addVal, addFront) // 插入
	return addVal
}

// 遍历知道对应的位置删除
func (this *ExamRoom) Leave(p int) {
	for e := this.seat.Front(); e != nil; e = e.Next() {
		if e.Value.(int) == p {
			this.seat.Remove(e)
			return
		}
	}
	return
}
```
