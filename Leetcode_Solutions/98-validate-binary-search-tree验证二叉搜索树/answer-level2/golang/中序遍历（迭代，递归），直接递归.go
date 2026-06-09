* 第一种解法：中序遍历，得到的是有序的结果，时间复杂度O（N），空间复杂度O（N）

	* 优化1:不使用数组，只保留上一个节点，比较两个节点

* 第二种解法：们需要在遍历树的同时保留结点的上界与下界，在比较时不仅比较子结点的值，也要与上下界比较。

	* 直接递归：时间复杂度O（N），空间复杂度O（N）

* 第三种解法：手动维护栈，使用迭代模拟递归方式中序遍历，时间复杂度O（N），空间复杂度O（N）


### 中序遍历

```
执行用时 :8 ms, 在所有 golang 提交中击败了93.24%的用户
内存消耗 :5.9 MB, 在所有 golang 提交中击败了24.27%的用户
```

```go

var arr []int
func isValidBST(root *TreeNode) bool {
	// terminator
	arr = make([]int, 0)
	inorder(root)
	for i:=1; i<len(arr); i++ {
		if arr[i] <= arr[i-1] {
			return false
		}
	}
	return true
}

func inorder(root *TreeNode) {
	// 左根右
	if root == nil {
		return
	}
	inorder(root.Left)
	arr = append(arr, root.Val)
	inorder(root.Right)
}

```

优化。不使用数组，只保留上一个节点

```
执行用时 :4 ms, 在所有 golang 提交中击败了99.73%的用户
内存消耗 :5.4 MB, 在所有 golang 提交中击败了81.55%的用户
```

```go
var lastNode *TreeNode
func isValidBST(root *TreeNode) bool {
	lastNode = nil
	return helper(root)
}

func helper(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if !helper(root.Left) {
		return false
	}
	if lastNode != nil && lastNode.Val >= root.Val {
		return false
	}
	lastNode = root
	return helper(root.Right)
}
```



### 直接递归

```
执行用时 :8 ms, 在所有 golang 提交中击败了93.24%的用户
内存消耗 :5.3 MB, 在所有 golang 提交中击败了100.00%的用户
```

```go
func isValidBST(root *TreeNode) bool {
	return helper2(root, math.MinInt64, math.MaxInt64)
}

// 解法2：直接递归，传左子树最大，和右子树最小
func helper2(root *TreeNode, min int, max int) bool {
	if root == nil {
		return true
	}
	if root.Val <= min || root.Val >= max {
		return false
	}
	return helper2(root.Left, min, root.Val) && helper2(root.Right, root.Val, max)
}
```



优化

```
执行用时 :4 ms, 在所有 golang 提交中击败了99.73%的用户
内存消耗 :5.3 MB, 在所有 golang 提交中击败了99.03%的用户
```

```go
// 验证二叉搜索树
func isValidBST(root *TreeNode) bool {
	return check(-1<<63, 1<<63-1, root)
}

func check(min, max int, node *TreeNode) bool {
	if node == nil {
		return true
	}
	return min < node.Val &&
		max > node.Val &&
		check(min, node.Val, node.Left) &&
		check(node.Val, max, node.Right)
}
```



```go
// 验证二叉搜索树
func isValidBST(root *TreeNode) bool {
	return check(root, -1 << 63, 1 << 63 - 1)
}

func check(root *TreeNode, min int, max int) bool {
	if root == nil {
		return true
	}
	return root.Val > min && root.Val < max && check(root.Left, min, root.Val) && check(root.Right, root.Val, max)
}
```

### 迭代，模拟递归栈
```go

type Stack []*TreeNode

func (stack *Stack) empty() bool {
	return len(*stack) == 0
}

func (stack *Stack) peek() *TreeNode {
	if stack.empty() {
		return nil
	}
	return (*stack)[len(*stack)-1]
}

func (stack *Stack) pop() *TreeNode {
	if stack.empty() {
		return nil
	}
	temp := (*stack)[len(*stack)-1]
	*stack = (*stack)[:len(*stack)-1]
	return temp
}

func (stack *Stack) push(temp *TreeNode) {
	*stack = append(*stack, temp)
}

// 使用迭代，手动维护栈
func isValidBST bool {
	if root == nil {
		return true
	}

	visited := make(map[*TreeNode]struct{})
	stack := Stack{root}
	var lastNode *TreeNode

	for !stack.empty() {
		node := stack.pop()
		if _, ok := visited[node]; ok {
			if lastNode != nil && node.Val <= lastNode.Val {
				return false
			}
			lastNode = node
		} else {
			// 入栈
			if node.Right != nil {
				stack.push(node.Right)
			}
			stack.push(node)
			visited[node] = struct{}{}
			if node.Left != nil {
				stack.push(node.Left)
			}
		}
	}
	return true
}
```