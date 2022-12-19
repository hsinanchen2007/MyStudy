### 解题思路
继承上一道
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedListToBST(head *ListNode) *TreeNode {
    if head == nil {
        return nil
    }
    nums := getVal(head)
    return buildTree(nums)
}

func getVal(head *ListNode) []int{
    res := make([]int, 0)
    for head != nil {
        res = append(res, head.Val)
        head = head.Next
    }
    return res
}

func buildTree(nums []int) *TreeNode{
    n := len(nums)
    if n == 0 {
        return nil
    }
    mid := n / 2
    res := &TreeNode{
        Val : nums[mid],
    }
    res.Left = buildTree(nums[:mid])
    res.Right = buildTree(nums[mid+1:])
    return res
}
```