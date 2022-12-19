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
    if l1==nil{
        return l2
    }else if l2==nil{
        return l1
    }
    var head,p,p1,p2 *ListNode
    if l1.Val<=l2.Val{
        head=l1
        p1=l1.Next
        p2=l2
    }else{
        head=l2
        p2=l2.Next
        p1=l1
    }
    p=head
    for{
        if p1==nil{
            p.Next=p2
            break
        }else if p2==nil{
            p.Next=p1
            break
        }else if p1.Val<=p2.Val{
            p.Next=p1
            p1=p1.Next
        }else{
            p.Next=p2
            p2=p2.Next
        }
        p=p.Next
    }
    return head
}
```