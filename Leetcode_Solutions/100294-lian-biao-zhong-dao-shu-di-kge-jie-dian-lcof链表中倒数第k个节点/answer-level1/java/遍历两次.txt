感觉反向也不会快多少
```
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode cur = head;
        int i = 0;
        while(cur != null) {
            i ++;
            cur = cur.next;
        }
        int j = 0;
        cur = head;
        while (j < (i - k)) {
            cur = cur.next;
            j++;
        }
        return cur;
    }
}
```
