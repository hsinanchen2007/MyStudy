### 解题思路
双指针前后俩个，前面都先走K下，后和前在一起走

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getKthFromEnd(head *ListNode, k int) *ListNode {
    
    ph := head
    pn := head
    for i:=0; i<k; i++ {
        ph = ph.Next
    }
    for ph != nil {
        ph = ph.Next
        pn = pn.Next
    }
    return pn
}
```