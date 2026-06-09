```
func reverseList(head *ListNode )*ListNode {

    if head==nil||head.Next==nil{
        return head
    }
    a:=[]*ListNode{}
    a=digui(head,a)
    for i:=0;i<len(a)-1;i++{
        a[i].Next=a[i+1]
    }
    return a[0]
}
func digui(head *ListNode,new []*ListNode)[]*ListNode{
 
    prev,cur:=head,head
    for cur.Next!=nil{
         prev=cur
        cur=cur.Next
        prev.Next=cur
    }
     new=append(new,cur) 
       if head.Next==nil{
        return new
            }
    prev.Next=nil
    return digui(head,new)
}
```
