![image.png](https://pic.leetcode-cn.com/2346ec4e413098e4f027ab82bac57323425e6e327ad83c3b148c59962e600a6a-image.png)

解题思路：
1.判断当前节点的值是否相当
2.递归判断左子树、右子树是否相等
```
func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p==nil && q!=nil {
		return false
	}

	if p!=nil && q==nil {
		return false
	}

	if p==nil && q==nil {
		return true
	}

	if p.Val != q.Val {
		return false
	}
	return isSameTree(p.Left,q.Left) && isSameTree(p.Right,q.Right)
}
```
