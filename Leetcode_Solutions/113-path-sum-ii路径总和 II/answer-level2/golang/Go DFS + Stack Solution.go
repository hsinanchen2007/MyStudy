思路是先 DFS 再使用栈进行回溯

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func NewStack() *Stack {
	s := make([]int, 0)
	return (*Stack)(&s)
}

type Stack []int

func (s *Stack) push(val int) {
	*s = append(*s, val)
}

func (s *Stack) pop() {
	size := len(*s)
	if size > 0 {
		*s = (*s)[:size-1]
	}
}

func (s *Stack) toSlice() []int {
	return append([]int{}, *s...)
}

func pathSum(root *TreeNode, sum int) (result [][]int) {
    var (
        helper func(*TreeNode, *Stack, int)
    )

    helper = func(node *TreeNode, s *Stack, total int) {
        if node == nil {
            return 
        }

        s.push(node.Val)
        total += node.Val
        if total == sum && node.Left == node.Right && node.Left == nil{
            result = append(result, s.toSlice())
        } else {
            helper(node.Left, s, total)
            helper(node.Right, s, total)
        }
        s.pop()
    }

    helper(root, NewStack(), 0)
    return result
}
```