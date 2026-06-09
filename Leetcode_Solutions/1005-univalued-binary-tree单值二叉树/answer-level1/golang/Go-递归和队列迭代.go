方法1：
递归，对节点进行比较得到结果，然后分别递归左子树和右子树

```
func isUnivalTree(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if root.Left != nil && root.Val != root.Left.Val {
		return false
	}
	if root.Right != nil && root.Val != root.Right.Val {
		return false
	}
	return isUnivalTree(root.Left) && isUnivalTree(root.Right)
}
```
![image.png](https://pic.leetcode-cn.com/875d004750fca6b380be181087f44c2f31fb9cce2d14984532f4a0732a638006-image.png)


方法2：
迭代，使用队列，BFS，将所有节点加入队列，并依次比较

```
func isUnivalTree(root *TreeNode) bool {
	var queue []*TreeNode
	queue = append(queue, root)
	for len(queue) > 0 {
		pop := queue[0]
		queue = queue[1:]
		if pop == nil {
			continue
		}
		if pop.Left != nil && pop.Val != pop.Left.Val {
			return false
		}
		if pop.Right != nil && pop.Val != pop.Right.Val {
			return false
		}
		queue = append(queue, pop.Left)
		queue = append(queue, pop.Right)
	}
	return true
}
```
![image.png](https://pic.leetcode-cn.com/9deae6add7c85f7b126654b7127372890d7905800fa3f52b86870475458ca3aa-image.png)
