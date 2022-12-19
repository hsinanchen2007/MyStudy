

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getDecimalValue(head *ListNode) int {
    ans := 0
    for ;head != nil;head = head.Next{
        ans = ans << 1 + head.Val
    }
    return ans
    
}
```