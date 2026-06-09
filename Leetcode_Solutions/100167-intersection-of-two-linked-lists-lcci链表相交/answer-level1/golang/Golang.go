### 解题思路
相当于A,B两人绕着操场跑步，若以相同的速度，又走过相同的路程，必有相遇之时。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    p,q := headA,headB
    for p!= q{
        if p == nil{
            p = headB
        }else{
            p = p.Next
        }
        if q == nil{
            q = headA
        }else{
            q = q.Next
        }
    }
    return p
    
}
```