const MaxLevel = 16

// 节点
type Node struct {
	Val       int     // 节点值
	NextNodes []*Node // 下一个节点所有层级
	Count     int     // 相同值数量
}

func NewNode(level int) *Node {
	return &Node{
		Val:       -1,
		NextNodes: make([]*Node, level),
		Count:     1,
	}
}

type Skiplist struct {
	levelCount int // 索引区间
	head       *Node
}

func Constructor() Skiplist {
	return Skiplist{
		levelCount: 1,
		head:       NewNode(MaxLevel),
	}
}

func randLevel() int {
	level := 1
	for i := 1; i < MaxLevel; i++ {
		if rand.Int31()%2 == 1 {
			level++
		}
	}
	return level
}

func (this *Skiplist) Search(target int) bool {
	var p = this.head
	for i := this.levelCount - 1; i >= 0; i-- {
		for p.NextNodes[i] != nil && p.NextNodes[i].Val < target {
			p = p.NextNodes[i]
		}
	}
	if p.NextNodes[0] != nil && p.NextNodes[0].Val == target {
		return true
	}
	return false
}

func (this *Skiplist) Add(num int) {
	var level int
	if this.head.NextNodes[0] == nil {
		level = 1
	} else {
		level = randLevel()
	}
	if level > this.levelCount {
		this.levelCount = this.levelCount + 1
		level = this.levelCount
	}
	var node = NewNode(level)
	node.Val = num
	var updates = make([]*Node, level)
	for i := 0; i < level; i++ {
		updates[i] = this.head
	}
	var p = this.head
	for i := level - 1; i >= 0; i-- {
		for p.NextNodes[i] != nil && p.NextNodes[i].Val <= num {
			p = p.NextNodes[i]
		}
		updates[i] = p
	}
	for i := 0; i < level; i++ {
		if updates[i].NextNodes[i] != nil && updates[i].NextNodes[i].Val == num {
			updates[i].NextNodes[i].Count = updates[i].NextNodes[i].Count + 1
		} else {
			node.NextNodes[i] = updates[i].NextNodes[i]
			updates[i].NextNodes[i] = node
		}
	}
}

func (this *Skiplist) Erase(num int) bool {
	var updates = make([]*Node, this.levelCount)
	var p = this.head
	for i := this.levelCount - 1; i >= 0; i-- {
		for p.NextNodes[i] != nil && p.NextNodes[i].Val < num {
			p = p.NextNodes[i]
		}
		updates[i] = p
	}
	if p.NextNodes[0] != nil && p.NextNodes[0].Val == num {
		for i := this.levelCount - 1; i >= 0; i-- {
			if updates[i].NextNodes[i] != nil && updates[i].NextNodes[i].Val == num {
				if updates[i].NextNodes[i].Count > 1 {
					updates[i].NextNodes[i].Count = updates[i].NextNodes[i].Count - 1
				} else {
					updates[i].NextNodes[i] = updates[i].NextNodes[i].NextNodes[i]
				}
			}
		}
		return true
	}
	return false
}