共三个解法，从朴素实现开始逐步优化：
```text
1.朴素实现：用一个集合来存储不断添加的日程；每次添加需要确定已有日程是否和要添加的日程有重叠
集合可以用list或切片；查找需要遍历集合，插入可以简单在末尾追加
假设已有日程有n个，时间复杂度为O(n),空间复杂度为集合的大小，O(n)
```
```go
type Interval struct {
    start, end int
}

type MyCalendar struct {
    calendar *list.List
}

func Constructor() MyCalendar {
    return MyCalendar{calendar: list.New()}
}

func (mc *MyCalendar) Book(start int, end int) bool {
    for e := mc.calendar.Front(); e != nil; e = e.Next() {
        interval := e.Value.(Interval)
        if max(start, interval.start) < min(end, interval.end) {
            return false
        }
    }
    mc.calendar.PushBack(Interval{start:start, end:end})
    return true
}

func max(a, b int) int {
	return int(math.Max(float64(a), float64(b)))
}

func min(a, b int) int {
	return int(math.Min(float64(a), float64(b)))
}
```
```text
2.二分法优化朴素实现：
可以维持集合里的日程有序(可依据每个日程的开始时间排序)，每次插入新日程就可以用二分法迅速找到要插入的位置
用list或堆（优先队列）的话，查找用不了二分法，这里可用切片，查找要插入的位置时间复杂度为O(lgn),
插入的话，因为要把待插入位置及其后边元素一一后移，时间复杂度是O(n)
综合最坏情况时间复杂度、空间复杂度与朴素实现相同，为O(n)；但是在普遍情况下要比朴素实现快,时间复杂度O(lgn)
```
```go
type Interval struct {
	start, end int
}

type MyCalendar struct {
	calendar []Interval
}

func Constructor() MyCalendar {
	return MyCalendar{}
}

func (mc *MyCalendar) Book(start int, end int) bool {
	pos := sort.Search(len(mc.calendar), func(i int) bool {
		return mc.calendar[i].start >= start
	})
	if pos < len(mc.calendar) && mc.calendar[pos].start < end ||
		pos-1 >= 0 && mc.calendar[pos-1].end > start {
		return false
	}
	insert(&mc.calendar, Interval{start:start, end:end}, pos)
	return true
}

// 在s中将val插入索引i处，插入前i及其后边元素一一后移
func insert(s *[]Interval, val Interval, i int) {
	if i == len(*s) {
		*s = append(*s, val)
		return
	}
	*s = append(*s, Interval{})
	_ = copy((*s)[i+1:len(*s)], (*s)[i:len(*s)-1])
	(*s)[i] = val
}
```
```text
3.进一步优化插入时间复杂度：
在插入新日程的时候，如果集合用切片，则有一一向后移动元素的复杂度在，
有没有一个数据结构能在常数时间插入元素，还能保证元素有序，且能在常数时间查询任意索引元素从而能用二分法做查询呢？
堆、list和切片都不行
二叉搜索树BST可堪此任，不过如果插入的顺序比较特别，bst会退化成一个链表
实际需要一个能维持平衡的搜索树，比如红黑树，像Java有TreeMap可用，Go标准库并没有这样的数据结构，手动实现起来有些复杂，暂不尝试
仅朴素BST来一把
时间复杂度最坏O(n), 平均情况O(lgn)；空间复杂度O(n)
```
```go
type Node struct {
	 left, right *Node
	 start, end int
}

func (n *Node) insert(node *Node) bool {
	if node.start >= n.end {
		if n.right == nil {
			n.right = node
			return true
		}
		return n.right.insert(node)
	}
	if node.end <= n.start {
		if n.left == nil {
			n.left = node
			return true
		}
		return n.left.insert(node)
	}
	return false
}

type MyCalendar struct {
	root *Node
}

func Constructor() MyCalendar {
	return MyCalendar{}
}

func (mc *MyCalendar) Book(start int, end int) bool {
	node := &Node{start:start, end:end}
	if mc.root == nil {
		mc.root = node
		return true
	}
	return mc.root.insert(node)
}
```
```text
实际测试，朴素BST的实现比朴素实现好一点，但是不比切片的实现好
有缘再手动实现下红黑树吧~~
```