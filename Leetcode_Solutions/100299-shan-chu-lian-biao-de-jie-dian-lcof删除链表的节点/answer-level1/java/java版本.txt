```java
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode dummy = new ListNode(-1);
        ListNode pre = dummy;
        dummy.next = head;
        while(pre.next != null){
            if(pre.next.val == val){
                pre.next = pre.next.next;
                return dummy.next;
            }
            pre = pre.next;
        }
        return dummy.next;
    }
}
```