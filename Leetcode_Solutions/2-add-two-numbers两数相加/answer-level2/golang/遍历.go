### 解题思路
低位逐步往高位相加，需要考虑进位的情况

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
   l3:=&ListNode{}
   var cur *ListNode
   cur=l3
   var num int
   for l1!=nil || l2!=nil{

       val:=cur.Val
       if l1!=nil{
          val+=l1.Val
          l1=l1.Next
       }
        if l2!=nil{
            val+=l2.Val
            l2=l2.Next
        }

        // 高位要进位
        num=val/10
          
        // 只保存10以内的数字，
        cur.Val=val%10
        //  进位
        if l1!=nil || l2!=nil || num>0{
                cur.Next=&ListNode{
                    Val:num,
                }
                cur=cur.Next
        }
   }
   
   return l3
}
```