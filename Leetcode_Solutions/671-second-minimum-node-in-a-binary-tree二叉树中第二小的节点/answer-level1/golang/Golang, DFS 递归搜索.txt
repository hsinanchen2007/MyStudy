### 解题思路

* runtime 0ms
* ram	2MB

感谢 ❤ [花花大佬的视频解题](http://zxi.mytechroad.com/blog/leetcode/leetcode-671-second-minimum-node-in-a-binary-tree/)


### 思路回顾

题目给出的BST有一个特性，就是根节点的值是这棵树里面最小的。
我们因此可以使用这个特性使用DFS快速完成搜索。

在递归的过程中:

*   如果当前树的根节点为空，返回`-1`，因为题目说明所有节点都是非负数。`-1`表示没找到。
*   如果当前树的根节点比我们已经找到的最小元素`s`要大，我们直接返回当前根节点的值，因为*输入是特殊的BST*它的子树不可能有比根节点大的值，我们可以直接返回当前值了，跳过对子树的递归。
*   上一个条件不满足，我们就要对当前树的左、右子树就行递归运算。
*   从左、右子树中选出最小值返回递归。



### 例子

树： 
```
        2
    /       \
    2       5
        /       \
        5       7

```

* 0  一开始: `dfs(root, 2)`，这里根节点值是`2`, 不比`2`大，因此递归调用在左子树，右子树上面。

* 11  第一层左子树：`dfs(root, 2)`，与01同样的情况, 因此调用在它的左右子树。
* 111 `dfs(nil, 2)`, 左子树为空，返回-1
* 112 `dfs(nil, 2)`, 右子树为空，返回-1
* 11  回到这个递归分支，返回-1，表示左子树没找到。返回0

* 21  第一层右子树`des(root, 2)`, 这里`5`比`2`大，直接返回`5`，分支结束。

* 0   左分支返回-1， 又分支返回5，递归结果返回5。递归结束。





### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findSecondMinimumValue(root *TreeNode) int {
	return dfs(root, root.Val)
}

// dfs is to find the second smallest element in this tree.
// s is the current smallest we have.
func dfs(root *TreeNode, s int) int {

	// If root is nil, that means we can't find anything,
	// we return -1
	if root == nil {
		return -1
	}

	// If the current tree value is bigger than the smallest
	// element we hat, that means we have found the second smallest
	// one in the tree, since all subtrees is greater or equal to this
	// value.
	if root.Val > s {
		return root.Val
	}

	sLeft := dfs(root.Left, s)
	sRight := dfs(root.Right, s)

	if sLeft == -1 {
		return sRight
	}

	if sRight == -1 {
		return sLeft
	}

	return min(sLeft, sRight)

}

// min a helper function
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

```