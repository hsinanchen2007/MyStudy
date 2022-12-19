

```

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {

     if l1 ==nil && l2==nil{
          return l1
     }
     if l1==nil{
         return l2
     }
     if l2 ==nil{
          return l1
     }

     var pre *ListNode
     if l1.Val<=l2.Val{
         pre =l1
         l1 = l1.Next
     }else {
         pre = l2
         l2 = l2.Next
     }
     ret :=pre
     for l1!=nil||l2!=nil{
          if l1 ==nil{
               pre.Next = l2
               break
          }
          if l2 ==nil{
               pre.Next =l1
               break
          }
          if l1.Val<=l2.Val{
               pre.Next =l1
               l1 = l1.Next
          }else {
               pre.Next =l2
               l2 = l2.Next
          }
          pre = pre.Next
     }

     return ret

}

```
