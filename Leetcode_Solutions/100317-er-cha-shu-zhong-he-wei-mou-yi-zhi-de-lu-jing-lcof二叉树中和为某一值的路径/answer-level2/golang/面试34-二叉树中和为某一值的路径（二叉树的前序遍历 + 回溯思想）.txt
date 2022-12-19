### 解题思路
学习[@jyd](/u/jyd/)大佬
[大佬详细讲解传送门](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/solution/mian-shi-ti-34-er-cha-shu-zhong-he-wei-mou-yi-zh-5/)

学习[@sakura-151](/u/sakura-151/)大佬
[大佬详细讲解传送门](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/solution/golang-di-gui-by-sakura-151-2/)

### 知识点：二叉树的前序遍历 + 回溯法

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
func pathSum(root *TreeNode, sum int) [][]int  {
	if root == nil {
		return nil
	}

	res := make([][]int, 0) // 结果切片
	recur(root, sum, []int{}, &res) // 递归函数
	return res
}

// 二叉树的搜索：前序遍历 + 回溯法
func recur(root *TreeNode, tar int, path []int, res *[][]int)  {
	if root == nil {
		return
	}

	path = append(path, root.Val)
	tar -= root.Val
    // 得到的路径符合要求时，创建一个新的切片，拷贝当前路径到其中，并添加到 ret 中
	if tar == 0 && root.Left == nil && root.Right == nil {
		// 保持各个路径切片path独立
		tmp := make([]int, len(path))
		copy(tmp, path)
		*res = append(*res, tmp)
	}

	recur(root.Left, tar, path, res)
	recur(root.Right, tar, path, res)
    
    // 得到的路径不符合要求，往前回溯，删除当前节点，返回父节点
	path = path[:len(path)-1] // 向上回溯前，需要将当前节点从路径 path 中删除
}
```