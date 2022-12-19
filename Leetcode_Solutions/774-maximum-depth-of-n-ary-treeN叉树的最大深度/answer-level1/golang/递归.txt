### 解题思路
树就递归完事儿

### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	return getDepth(root) + 1

}

func getDepth(root *Node) int {
	if len(root.Children) == 0 {
		return 0
	}

	currentDepth := 0
	for _, child := range root.Children {
		currentDepth =  max(currentDepth, getDepth(child)+1)
	}
    return currentDepth
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
```