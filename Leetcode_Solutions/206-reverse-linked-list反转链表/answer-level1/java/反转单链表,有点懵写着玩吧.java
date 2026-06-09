```
class Solution {
    public static ListNode reverseList(ListNode head) {
        ListNode p = null, q = head, m=null;
        while (q != null) {
            m = q.next;
            q.next = p;
            p = q;
            q = m;
        }
        return p;
    }
}
```
