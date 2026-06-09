```
public ListNode deleteNode(ListNode head, int val) {
    if(head==null)return null;
    if(head.val==val){
        head=head.next;
        return head;
    }
    ListNode p=head;
    while(p.next!=null){
        if(p.next.val==val){
            p.next=p.next.next;
            return head;
        }
        p=p.next;
    }
    return head;
}
```
