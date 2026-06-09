二叉搜索树的特性是左子树的值小于根节点的值，右子树的值大于根节点

后续遍历的顺序是左-右-根

因此，给定一个数组，我们可以比较数值的大小找到它的左子树和右子树，递归地重构数组对应的二叉搜索树
```go []
func verifyPostorder(postorder []int) bool {
	if len(postorder)<=1{
		return true
	}
	l:=len(postorder)
	root:=postorder[l-1]//根元素的值
	flag:=0
	// 找到二叉搜索树比根的值大的点的第一个人索引
	for i:=l-2;i>=0;i-- {
		if postorder[i] <root{
			flag=i+1
			break
		}
	}
	// 索引左边的值都应该小于根节点的值，若有大于的 返回false
	for i:=0;i<flag;i++ {
		if postorder[i]>root{
			return false
		}
	}
	// 继续判断根的左子树和右子树是否满足二叉搜索树的要求
	return verifyPostorder(postorder[:flag])&&verifyPostorder(postorder[flag:l-1])
}
```


