# 思考

- 如果两棵二叉树root1、root2相等，那么root1与root2节点的值相同，
- 同时它们的左右孩子也有着相同的结构，并且对应位置上节点的值相等，即 `root1.data==root2.data` ，
- 并且root1的左子树与root2的左子树相等，root1的右子树与root2的右子树相等。

根据这个条件，可以写出判断两棵二叉树是否相等的递归算法。

# Go实现

```go
package main

import (
	"fmt"
)

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p == nil && q != nil {
		return false
	}
	if p != nil && q == nil {
		return false
	}
	if q.Val == p.Val {
		return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
	}
	return false
}
func CreateTree() *TreeNode {
	root := &TreeNode{}
	node1 := &TreeNode{}
	node2 := &TreeNode{}
	root.Val = 1
	node1.Val = 2
	node2.Val = 3
	root.Left = node1
	root.Right = node2
	return root
}
func main() {
	p := CreateTree()
	q := CreateTree()
	fmt.Println(isSameTree(p, q))
}

```

# 代码优化
学习代码[画解算法](https://leetcode-cn.com/problems/same-tree/solution/hua-jie-suan-fa-100-xiang-tong-de-shu-by-guanpengc/)

终止条件与返回值：

- 当两棵树的当前节点都为null时，返回true
- 当其中一个为null另一个不为null时，返回false
- 当两个都不为空但是值不相等时，返回false

执行过程:

当满足终止条件时进行返回，不满足时分别判断左子树和右子树是否相同，其中要注意代码中的短路效应。

时间复杂度: O(n)，n为树的节点个数。

```go
func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil {
		return false
	}
	if q.Val != p.Val {
		return false
	}
	return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}
```