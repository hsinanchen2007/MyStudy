### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    if head==nil{
        return nil
    }
    first:=head
    second:=first.Next
    for second!=nil{
        c:=second.Next
        second.Next=first
        first=second
        second=c
        //end.Next=first

    }
    head.Next=nil
    return first
    }
```