自建一个树结构，通过旋转维护主结点两侧平衡，非主流解法，娱乐。。
```
type Node struct {
	LeftNode  *Node
	RightNode *Node
	value       int
	banlance     int
}

type MedianFinder struct {
	node *Node
}


/** initialize your data structure here. */
func Constructor() MedianFinder {
	return MedianFinder{
	}
}

func (m *Node) findR() (p *Node,sub *Node){
	var a *Node
	for {
		a = m.RightNode
		if a.RightNode == nil {
			return m,a
		}
		m = a
	}

}

func (m *Node) findL() (p *Node,sub *Node){
	var a *Node
	for {
		a = m.LeftNode
		if a.LeftNode == nil {
			return m,a
		}
		m = a
	}
}

func (this *MedianFinder) AddNum(num int)  {
	b := this.node
	if b ==nil{
		b = &Node{banlance:-1,value:num}

	}else if b.value >= num {
		b.Add(num)
		b.banlance = b.banlance-1
	} else {
		b.Add(num)
		b.banlance = b.banlance+1
	}
	var p *Node
	if b.banlance ==-2{
		a := b
		if a.LeftNode.RightNode == nil{
			b = a.LeftNode
			a.LeftNode =nil
			b.RightNode = a
		}else{
			p,b =b.LeftNode.findR()
			p.RightNode = b.LeftNode
			b.LeftNode = a.LeftNode
			a.LeftNode =nil
			b.RightNode = a
		}
		b.banlance = 0
	}else if b.banlance == 1{
		a := b
		if a.RightNode.LeftNode == nil{
			b = a.RightNode
			a.RightNode =nil
			b.LeftNode = a
		}else{
			p,b =b.RightNode.findL()
			p.LeftNode = b.RightNode
			b.RightNode = a.RightNode
			a.RightNode =nil
			b.LeftNode = a
		}
		b.banlance = -1
	}

	this.node = b
}


func (n *Node) Add(num int) {
	if n.value >= num {
		if n.LeftNode == nil {
			n.LeftNode = &Node{value:num}
			return
		}
		n.LeftNode.Add(num)
	}
	if n.value < num {
		if n.RightNode == nil{
			n.RightNode = &Node{value:num}
			return
		}
		n.RightNode.Add(num)
	}

}


func (this *MedianFinder) FindMedian() float64 {
	if this.node.banlance ==-1 {
		return float64(this.node.value)
	}else {
		if this.node.RightNode.LeftNode == nil {
			return float64(this.node.value+this.node.RightNode.value) / 2
		}else {
			_, sub := this.node.RightNode.findL()
			return float64(this.node.value+sub.value) / 2
		}
	}


}
```