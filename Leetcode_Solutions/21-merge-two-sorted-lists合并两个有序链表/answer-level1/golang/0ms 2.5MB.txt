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
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {

    head:=&ListNode{}
    temp:=head
    for l1!=nil && l2!=nil{
        if l1.Val < l2.Val {
            temp.Next=l1
            l1=l1.Next 
            
        }else{
            temp.Next=l2
            l2=l2.Next 
        }
        temp=temp.Next
    }
    if l1==nil && l2!=nil {
        temp.Next=l2
    }
    if l1!=nil && l2==nil{
        temp.Next=l1
    }
    return head.Next
}
```