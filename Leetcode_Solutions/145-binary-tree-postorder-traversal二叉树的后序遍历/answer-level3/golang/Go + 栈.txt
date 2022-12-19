```
type elem struct {
	Node *TreeNode
	Type int
}

var (
	typeTree = 1
	typeVal  = 2
)

func postorderTraversal(root *TreeNode) (rst []int) {
	if root == nil {
		return nil
	}
	var l = list.New()
	l.PushBack(elem{Node: root, Type: typeVal})
	l.PushBack(elem{Node: root.Right, Type: typeTree})
	l.PushBack(elem{Node: root.Left, Type: typeTree})
	for l.Len() != 0 {
		e := l.Back()
		l.Remove(e)
		currElem := e.Value.(elem)
		switch currElem.Type {
		case typeVal:
			rst = append(rst, currElem.Node.Val)
		case typeTree:
			if currElem.Node == nil {
				continue
			}
			l.PushBack(elem{Node: currElem.Node, Type: typeVal})
			l.PushBack(elem{Node: currElem.Node.Right, Type: typeTree})
			l.PushBack(elem{Node: currElem.Node.Left, Type: typeTree})
		}
	}

	return
}
```
