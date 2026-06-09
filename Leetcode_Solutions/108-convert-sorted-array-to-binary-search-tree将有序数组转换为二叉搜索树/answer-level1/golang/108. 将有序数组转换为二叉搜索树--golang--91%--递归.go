### 解题思路
将所给排序数组从中间分开，中间节点取为根节点，左右区间分别为左右子树，利用递归进行构造二叉树。

递归不用思考每一个细节，只需要将最后一个子问题分析清楚，设定好终止条件就能完成构造。

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
func sortedArrayToBST(nums []int) *TreeNode {
        l := len(nums)
        mid := l/2
        if l == 0 {
            return nil          
        }
        p := new(TreeNode)
        p.Val = nums[mid]
        p.Left = sortedArrayToBST(nums[:mid])
        p.Right = sortedArrayToBST(nums[mid+1:])

        return p
}
```