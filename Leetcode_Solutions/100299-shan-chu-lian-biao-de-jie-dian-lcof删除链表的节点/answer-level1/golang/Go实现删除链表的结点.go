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
func deleteNode(head *ListNode, val int) *ListNode {
    if head == nil{
        return nil
    }
    dummnyhead := &ListNode{Val:-1,Next:head}
    cur := dummnyhead
    for cur.Next != nil{
        if cur.Next.Val == val{
            cur.Next = cur.Next.Next
        }else{
            cur = cur.Next
        }
    }
    return dummnyhead.Next
}
```