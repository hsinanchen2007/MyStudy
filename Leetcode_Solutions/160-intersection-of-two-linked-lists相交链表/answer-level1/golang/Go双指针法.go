### 解题思路
巧妙运用两指针经过的路程相等。
指针a经过的路程：A全程+B到交点=A到交点+交点到结尾+B到交点
指针b经过的路程：B全程+A到交点=B到交点+交点到结尾+A到交点
所以如果有交点的话a、b两指针一定会在交点相遇

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
    a2b,b2a:=false,false
    for{
        if pa==pb{
            return pa
        }
        if pa.Next==nil{
            if !a2b{
                pa=headB
                a2b=true
            }else{
                return nil
            }
        }else{
            pa=pa.Next
        }
        if pb.Next==nil{
            if !b2a{
                pb=headA
                b2a=true
            }else{
                return nil
            }
        }else{
            pb=pb.Next
        }
    }
}
```