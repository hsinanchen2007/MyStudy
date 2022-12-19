# 解题思路
**二叉搜索树（Binary Search Tree）**，（又：二叉查找树，二叉排序树）
- 它或者是一棵空树，或者是具有下列性质的二叉树： 
 	- 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
 	- 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 
 	- 它的左、右子树也分别为二叉搜索树。

**中序遍历（LDR）**
- 是二叉树遍历的一种，也叫做中根遍历、中序周游。
- 在二叉树中，中序遍历**首先遍历左子树，然后访问根结点，最后遍历右子树**。

---
# 代码

 - 中序遍历二叉搜索树，遍历的同时，把遍历到的节点数值存到一个可变切片里 
 - 中序遍历的顺序为左中右，即得到的是一个递增序列
 - 逆中序遍历的顺序为右中左，即得到的是一个递减序列 
 - 使用逆中序遍历在返回数组中的第 K-1 个即可得到结果

--执行用时：16 ms --内存消耗：6.3 MB
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargest(root *TreeNode, k int) int {
    var nums []int
    nums=getNums(&nums,root)
    return nums[k-1]
}

//逆中序遍历（右中左 -- 递减序列）
func getNums(nums *[]int,r *TreeNode) []int{
    if r.Right!=nil{
        getNums(nums,r.Right)
    }
    if r!=nil{
        *nums=append(*nums,r.Val)
    }
    if r.Left!=nil{
        getNums(nums,r.Left)
    }
    return *nums
}
```
---
# 优化：遍历到第K大则停止遍历
--执行用时：8 ms --内存消耗：5.9 MB
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var count int

func kthLargest(root *TreeNode, k int) int {
    count=0
    var nums []int
    nums=getNums(&nums,root,k)
    return nums[k-1]
}

//逆中序遍历（右中左 -- 递减序列）
func getNums(nums *[]int,r *TreeNode,k int) []int{
    if r.Right!=nil{
        getNums(nums,r.Right,k)
    }
    if count<k && r!=nil{
        *nums=append(*nums,r.Val)
        count++
    }
    if r.Left!=nil{
        getNums(nums,r.Left,k)
    }
    return *nums
}
```
