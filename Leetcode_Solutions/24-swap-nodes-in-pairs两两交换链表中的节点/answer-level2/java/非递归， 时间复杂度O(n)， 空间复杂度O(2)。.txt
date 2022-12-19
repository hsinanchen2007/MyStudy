```
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head==null)
            return null;
        ListNode headPre = new ListNode(0);
        headPre.next = head;
        ListNode tmp = headPre;
        ListNode mem;
        ListNode mem1;
        
        while (tmp.next != null && tmp.next.next != null) {
            mem = tmp.next;
            mem1 = tmp.next.next.next;
            tmp.next = tmp.next.next;
            tmp.next.next = mem;
            mem.next = mem1;
            tmp = tmp.next.next;
        }
        
        return headPre.next;
    }
}
```
