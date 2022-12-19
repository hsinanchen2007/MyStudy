方法1：
递归实现，利用辅助函数isMirror，首先判断当前节点是否是镜像的，然后递归判断其左节点和右节点

```
func isSymmetric(root *TreeNode) bool {
	return isMirror(root, root)
}

func isMirror(t1 *TreeNode, t2 *TreeNode) bool {
	if t1 == nil && t2 == nil {
		return true
	}
	if t1 == nil || t2 == nil {
		return false
	}
	return t1.Val == t2.Val && isMirror(t1.Left, t2.Right) && isMirror(t1.Right, t2.Left)
}
```
![image.png](https://pic.leetcode-cn.com/33858fc4e45725fc39c76e41e1e36f98972cdd032d1343de6b8db90566904cc3-image.png)


方法2：
迭代实现，类似于BFS，使用队列的方式，每次从队列头取出两个，即为比较的左右树，分别比较左右树是否Val一致，然后将左右树的左右子树以镜像的方式放到队列中。
初始将root分别作为左右树放入
golang没有原生的队列，可以直接使用slice的特性来实现

```
func isSymmetric(root *TreeNode) bool {
	var queue []*TreeNode
	queue = append(queue, root)
	queue = append(queue, root)
	for len(queue) >= 2 {
		t1 := queue[0]
		t2 := queue[1]
		queue = queue[2:]
		if t1 == nil && t2 == nil {
			continue
		}
		if t1 == nil || t2 == nil {
			return false
		}
		if t1.Val != t2.Val {
			return false
		}
		queue = append(queue, t1.Left)
		queue = append(queue, t2.Right)
		queue = append(queue, t1.Right)
		queue = append(queue, t2.Left)
	}
	return true
}
```
![image.png](https://pic.leetcode-cn.com/0ae9d5d0d87fdffb744a0cf0104c18585446589289b6c1ba8b089798a677f0ec-image.png)
