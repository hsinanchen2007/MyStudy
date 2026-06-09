二叉树就递归呗，还能咋着。
以s的每个结点为根的子树和 t做一次相等比较。 比较的过程也是个递归。
总之递归就对了。
```
func isSubtree(s *TreeNode, t *TreeNode) bool {
    if s == nil {
		return false
	}
	return isSubtree(s.Left, t) || equal(s, t) || isSubtree(s.Right, t)
}

func equal(s, t *TreeNode) bool {
	if s == nil && t == nil {
		return true
	}
	if s == nil || t == nil {
		return false
	}
	if s.Val != t.Val {
		return false
	}
	return equal(s.Left, t.Left) && equal(s.Right, t.Right)
}
```
提交结果
![image.png](https://pic.leetcode-cn.com/de59960ce9229b44e3352a3544f912412fdc756c9fe9fdc561821a3aed392dba-image.png)


