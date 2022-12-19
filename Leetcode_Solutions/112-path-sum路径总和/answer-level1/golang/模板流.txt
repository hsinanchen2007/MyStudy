### 解题思路
1.叶节点的意思是左右都没节点
2.然后这题是不是像极了 `前序遍历` ，模板手速一把梭
[Go版本 Github](https://github.com/temporaries/leetcode)
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree/preorder.go)
[本题完整代码 Github](https://github.com/temporaries/leetcode/blob/master/tree/0112.path-sum)

### 代码

```golang
func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	}
	if root.Left == nil && root.Right == nil {
		return sum == root.Val
	}
	return hasPathSum(root.Left, sum-root.Val) || hasPathSum(root.Right, sum-root.Val)
}
```