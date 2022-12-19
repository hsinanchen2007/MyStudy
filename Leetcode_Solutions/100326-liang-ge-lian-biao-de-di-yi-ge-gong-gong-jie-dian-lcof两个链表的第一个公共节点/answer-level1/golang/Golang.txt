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
    if headA==nil||headB==nil{
        return nil
    }
    pa,pb:=headA,headB
    flagA,flagB:=false,false
    for{
        if pa==pb{
            return pa
        }else if pa==nil&&flagA||pb==nil&&flagB{
            return nil
        }
        if pa==nil{
            pa=headB
            flagA=true
        }else{
            pa=pa.Next
        }
        if pb==nil{
            pb=headA
            flagB=true
        }else{
            pb=pb.Next
        }
    }
    return nil
}
```