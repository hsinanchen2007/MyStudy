```go
func reverseList(head *ListNode) *ListNode {
    cur := head
    var prev *ListNode
    for cur != nil{
        n:= cur.Next
        cur.Next = prev

        prev = cur
        cur = n
        
    }

    return prev
}
```


```go
//reverse method
func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    _,reverseHead:=helper(head)
    return reverseHead
}

func helper(head *ListNode) (*ListNode,*ListNode){
    if head.Next == nil {
        return head,head
    }
    
    //  head为3 node为4（即反转当前结点3） 反转前状态1->2->3->4<-5 反转后状态1->2->3<-4<-5
    node,reverseHead := helper(head.Next)
    node.Next = head
    head.Next = nil
    return head,reverseHead
}

```