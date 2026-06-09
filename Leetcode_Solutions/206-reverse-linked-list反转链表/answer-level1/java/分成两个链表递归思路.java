```
class Solution {
    public ListNode reverseList(ListNode head) {
        return reverse(null, head);
    }

    private ListNode reverse(ListNode pre, ListNode cur) {
    if (cur == null) {
      return pre;
    }
    ListNode next = cur.next;
    cur.next = pre;
    return reverse(cur, next);
  }
}
```
