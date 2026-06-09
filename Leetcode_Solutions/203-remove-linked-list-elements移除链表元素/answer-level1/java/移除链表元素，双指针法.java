java实现，双指针法。
```
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode soldier = new ListNode(0);
        ListNode q = new ListNode(0);
        q.next = head;
        soldier.next = q;
        ListNode p = head;
        while(p != null){
            if(p.val != val){
                q.next = p; 
                q = q.next;
            }
            p = p.next;
         }
        q.next = null;
        return soldier.next.next;
    }
}
```