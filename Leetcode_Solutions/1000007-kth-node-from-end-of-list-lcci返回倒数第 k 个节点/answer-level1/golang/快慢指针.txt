### 解题思路
快慢指针，先让两个指针之间的距离为k，然后一起向后移动，快指针走到链尾的时候慢指针就是倒数第k个

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func kthToLast(head *ListNode, k int) int {
    var (
        pSlow *ListNode = head
        pFast *ListNode = head
    )
    for i := 0; i<k-1; i++ {
        pFast = pFast.Next
    }

    for pFast.Next != nil {
        pFast = pFast.Next
        pSlow = pSlow.Next
    }
    return pSlow.Val
}
```