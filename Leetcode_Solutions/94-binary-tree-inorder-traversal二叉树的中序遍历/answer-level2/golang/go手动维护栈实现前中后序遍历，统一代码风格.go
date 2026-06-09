使用栈的话本质就是手动模拟递归调用栈，为了能像递归一样写出风格统一且简洁的代码，这里维护一个visited的map，来标记访问过的节点。
* 中序遍历，要求顺序是左根右，入栈时就要按照相反的顺序入栈，即右根左；
* 前序遍历，要求顺序是根左右，入栈时就要按照相反的顺序入栈，即右左根；
* 后序遍历，要求顺序是左右根，入栈时就要按照相反的顺序入栈，即根右左。

首先自己写一个栈stack的简单实现
```go
type Stack struct {
	data []*TreeNode
}

func (stack *Stack) push(node *TreeNode) {
	stack.data = append(stack.data, node)
}

func (stack *Stack) pop() *TreeNode {
	if stack.isEmpty() {
		return nil
	}
	temp := stack.data[len(stack.data)-1]
	stack.data = stack.data[:len(stack.data)-1]
	return temp
}

func (stack *Stack) peek() *TreeNode {
	if stack.isEmpty() {
		return nil
	}
	return stack.data[len(stack.data)-1]
}

func (stack Stack) isEmpty() bool {
	return len(stack.data) == 0
}
```
实现中序遍历
```go
// 迭代，手动使用栈来模拟递归调用栈
func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	visited := make(map[*TreeNode]struct{})
	stack := Stack{data: []*TreeNode{root}}
	res := []int{}
	for !stack.isEmpty() {
		node := stack.pop()
		if _, ok := visited[node]; ok {
			res = append(res, node.Val)
		} else {
			// 右
			if node.Right != nil {
				stack.push(node.Right)
			}
			// 根
			stack.push(node)
			visited[node] = struct{}{}
			// 左
			if node.Left != nil {
				stack.push(node.Left)
			}
		}
	}
	return res
}
```

前序遍历
```go
func preorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	visited := make(map[*TreeNode]struct{})
	stack := Stack{data: []*TreeNode{root}}
	res := []int{}
	for !stack.isEmpty() {
		node := stack.pop()
		if _, ok := visited[node]; ok {
			res = append(res, node.Val)
		} else {
			// 右
			if node.Right != nil {
				stack.push(node.Right)
			}
			// 左		
			if node.Left != nil {
				stack.push(node.Left)
			}
			// 根
			stack.push(node)
			visited[node] = struct{}{}
		}
	}
	return res
}
```

后序遍历
```go
func postorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	visited := make(map[*TreeNode]struct{})
	stack := Stack{data: []*TreeNode{root}}
	res := []int{}
	for !stack.isEmpty() {
		node := stack.pop()
		if _, ok := visited[node]; ok {
			res = append(res, node.Val)
		} else {
			// 根
			stack.push(node)
			visited[node] = struct{}{}
			// 右
			if node.Right != nil {
				stack.push(node.Right)
			}
			// 左
			if node.Left != nil {
				stack.push(node.Left)
			}
		}
	}
	return res
}
```
