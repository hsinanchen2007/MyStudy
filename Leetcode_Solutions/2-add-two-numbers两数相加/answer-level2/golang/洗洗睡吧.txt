### 解题思路
打卡
### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    head:=l1
    for l1!=nil&&l2!=nil{
        l1.Val+=l2.Val
        if l1.Next==nil{
            l1.Next=l2.Next
            break
        }
        l1=l1.Next
        l2=l2.Next
    } 
    for l1=head;l1!=nil;l1=l1.Next{
        if l1.Val>=10{
            l1.Val-=10
            if l1.Next!=nil{
                l1.Next.Val++
            }else{
                node:=&ListNode{ Val:1,Next:nil }
                l1.Next=node
            }
        }
    }  
    return head
}
```