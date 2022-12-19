```
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        while(head != null && head.val == val)  head = head.next;
        if(head == null)    return head;

        ListNode p = head;
        ListNode q = head;

        while(p != null){
            if(p.val == val)    q.next = p.next;
            else    q = p;
            p = p.next;
        }
        return head;
    }
}
```
