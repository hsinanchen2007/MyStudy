### 解题思路
此处撰写解题思路

### 代码
多重赋值，交换两个节点的next指针，重点在于如是剩下只有一个节点，那么就不用交换了
```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
        if head==nil ||head.Next ==nil {
            return head
        }
        pre:=&ListNode{}
        pre.Next=head
        first:=pre
        for head.Next !=nil {
            pre.Next,head.Next,head.Next.Next =head.Next,head.Next.Next,head
            if head.Next !=nil {
                 pre,head=head,head.Next
            }
        }
        return first.Next
}
```