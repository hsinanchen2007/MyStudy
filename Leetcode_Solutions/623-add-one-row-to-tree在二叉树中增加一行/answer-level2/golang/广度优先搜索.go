```
func main() {
	n1 := &TreeNode{
		Val: 3,
	}
	n2 := &TreeNode{
		Val: 1,
	}
	n3 := &TreeNode{
		Val: 5,
	}
	n4 := &TreeNode{
		Val:   2,
		Left:  n1,
		Right: n2,
	}
	n5 := &TreeNode{
		Val:  6,
		Left: n3,
	}
	n6 := &TreeNode{
		Val:   4,
		Left:  n4,
		Right: n5,
	}

	if b, err := json.Marshal(addOneRow(n6, 1, 2)); err == nil {
		fmt.Println("================struct 到json str==")
		fmt.Println(string(b))
	}
}

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func addOneRow(root *TreeNode, v int, d int) *TreeNode {
	if d == 1 {
		newNode := &TreeNode{
			Val:  v,
			Left: root,
		}
		return newNode
	}
	root = addOneRowWithD(root, true, 1, v, d)
	return root
}

func addOneRowWithD(node *TreeNode, left bool, depth, v, d int) *TreeNode {
	if depth == d {
		newNode := &TreeNode{
			Val: v,
		}
		if left {
			newNode.Left = node
		} else {
			newNode.Right = node
		}
		return newNode
	}
	if node == nil {
		return node
	}
	node.Left = addOneRowWithD(node.Left, true, depth+1, v, d)
	node.Right = addOneRowWithD(node.Right, false, depth+1, v, d)
	return node
}


```