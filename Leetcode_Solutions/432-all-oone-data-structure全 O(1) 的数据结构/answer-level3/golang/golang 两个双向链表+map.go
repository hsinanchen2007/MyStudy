### 解题思路
此处撰写解题思路

### 代码

```golang
//数据存储节点，相同value的构成一个双向链表
type Node struct {
	Key string
	Val int
	Pre *Node
	Next *Node
}

//value存储节点，从小到大存储value，构成一个双向链表
type ValNode struct {
	Val int
	NodeList *Node //指向数据存储节点的双向链表
	Pre *ValNode
	Next *ValNode
	Size int
}

type AllOne struct {
	KeyMap map[string]*Node //Key和node的存储map
	ValNodeMap map[int]*ValNode //value和valueNode的存储map
	Head *ValNode
	Tail *ValNode
}


/** Initialize your data structure here. */
func Constructor() AllOne {
    head := new(ValNode)
	tail := new(ValNode)
	head.Next = tail
	tail.Pre = head
	return AllOne{
		KeyMap: make(map[string]*Node),
		ValNodeMap: make(map[int]*ValNode),
		Head: head,
		Tail: tail,
	}
}

func NewValNode(val int) *ValNode {
	valNode := new(ValNode)
	valNode.Size = 0
	valNode.Val = val
	return valNode
}

func (this *AllOne) insertNode(node *Node, isInc bool) {
    //如果对应的value的valNode存证，则直接插入到其node链表的头
	if valNode, ok := this.ValNodeMap[node.Val]; ok {
		firstNode := valNode.NodeList
		node.Next = firstNode
		firstNode.Pre = node
		valNode.NodeList = node
		valNode.Size++
	} else {
		valNode := NewValNode(node.Val)

        //针对Inc，之前的值是当前值-1
        //将新的valNode插入到valNode链表
		if isInc {
			preNodeVal := node.Val-1
			var p, n *ValNode
            //当为node的val为1时，需要特殊处理一下
			if preNodeVal == 0 {
				p = this.Head
				n = p.Next
			} else {
				p = this.ValNodeMap[preNodeVal]
				n = p.Next
			}


			valNode.Next = n
			p.Next = valNode
			valNode.Pre = p
			n.Pre = valNode
		} else {
            //针对Dec，之前值是当前值+1
            //将新的valNode插入到valNode链表
			nextNodeVal := node.Val+1
			n := this.ValNodeMap[nextNodeVal]
			p := n.Pre

			valNode.Next = n
			p.Next = valNode
			valNode.Pre = p
			n.Pre = valNode
		}

		this.ValNodeMap[node.Val] = valNode
		valNode.NodeList = node
		valNode.Size++
	}
}

//在对应的valNode节点下的双向链表中删除node
func (this *AllOne) deleteNode(node *Node) {
	valNode := this.ValNodeMap[node.Val]
	if node.Pre != nil {
		node.Pre.Next = node.Next
		if node.Next != nil {
			node.Next.Pre = node.Pre
		}
	} else {
		valNode.NodeList = node.Next
	}
	valNode.Size--
}

//调整node在valueNode双向链表中的位置
func (this *AllOne) adjustNode(node *Node, isInc bool) {
    //先删除node
	this.deleteNode(node)

	preVal := node.Val
	if isInc {
		node.Val++
	} else {
		node.Val--
	}
	node.Pre = nil
	node.Next = nil

    //node的value变化后，将node插入到对应的valueNode的双向链表下面
	this.insertNode(node, isInc)
	valNode := this.ValNodeMap[preVal]

    //如果valNode下的双向链表node了，删除valNode
	if valNode.Size == 0 {
		valNode.Pre.Next = valNode.Next
		valNode.Next.Pre = valNode.Pre
		delete(this.ValNodeMap, preVal)
	}
}

/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
func (this *AllOne) Inc(key string)  {
    if node, ok := this.KeyMap[key]; ok {
		this.adjustNode(node, true)
	} else {
		node = new(Node)
		node.Val = 1
		node.Key = key
		this.insertNode(node, true)
		this.KeyMap[key] = node
	}
}


/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
func (this *AllOne) Dec(key string)  {
    var ok bool
	var node *Node
	if node, ok = this.KeyMap[key]; ok {
		if node.Val == 1 {
			delete(this.KeyMap, key)
			this.deleteNode(node)
			valNode := this.ValNodeMap[node.Val]
			if valNode.Size == 0 {
				valNode.Pre.Next = valNode.Next
				valNode.Next.Pre = valNode.Pre
				delete(this.ValNodeMap, node.Val)
			}
		} else {
			this.adjustNode(node, false)
		}
	}
}


/** Returns one of the keys with maximal value. */
func (this *AllOne) GetMaxKey() string {
    if this.Tail.Pre != this.Head {
		valNode := this.Tail.Pre
		return valNode.NodeList.Key
	}
	return ""
}


/** Returns one of the keys with Minimal value. */
func (this *AllOne) GetMinKey() string {
    if this.Head.Next != this.Tail {
		valNode := this.Head.Next
		return valNode.NodeList.Key
	}
	return ""
}


/**
 * Your AllOne object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Inc(key);
 * obj.Dec(key);
 * param_3 := obj.GetMaxKey();
 * param_4 := obj.GetMinKey();
 */
```