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
func middleNode(head *ListNode) *ListNode {
    temp := head
    count := []int{}
    for {
        count = append(count,head.Val)
        if head.Next == nil {
            break
        }
        head = head.Next
    }
    middle := len(count)/2
    for i:=0;i<middle;i++ {
        temp = temp.Next
    }
    return temp
}
```