```
if(head == null)
    return null;
if (head.next == null)
    return head;
ListNode temp = head, pre = null, next = head.next;
head = head.next;
boolean odd = true;
while (next != null) {
    if (odd) {
        if(pre != null)
            pre.next = next;
        temp.next = next.next;
        next.next = temp;
        ListNode t = temp;
        temp = next;
        next = t;
    } 
    
    pre = temp;
    temp = next;
    next = next.next;

    odd = !odd;
}
return head;
```
