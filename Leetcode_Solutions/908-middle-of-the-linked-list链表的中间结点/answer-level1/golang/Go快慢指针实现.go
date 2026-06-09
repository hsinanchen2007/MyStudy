### 解题思路
快指针一次前进2个节点，慢指针一次前进一个，当快指针到头的时候慢指针指向的就是中点。

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
    if head==nil{
        return head
    }
    slow,fast:=head,head
    for{
        if fast.Next!=nil&&fast.Next.Next!=nil{
            fast=fast.Next.Next
            slow=slow.Next
        }else if fast.Next!=nil{
            return slow.Next
        }else{
            return slow
        }
    }
}
```