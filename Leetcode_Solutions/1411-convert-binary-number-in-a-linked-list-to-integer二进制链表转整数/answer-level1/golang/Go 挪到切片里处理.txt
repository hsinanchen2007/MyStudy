### 解题思路


### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getDecimalValue(head *ListNode) int {
    var result int
    var dec []int
    if head == nil {
        return 0
    }
    for head != nil {
        dec = append(dec,head.Val)
        head = head.Next
    }
    for i:=len(dec)-1; i>=0; i--{
        result += dec[i]<<(len(dec)-1-i)
    } 
    return result
}
```