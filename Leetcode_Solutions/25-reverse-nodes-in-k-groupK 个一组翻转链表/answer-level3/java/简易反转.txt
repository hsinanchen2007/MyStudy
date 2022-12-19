**思路: 检查是否有k长, 逆转k个, 并继续操作下k个**
与普通链表反转并无太大区别, 应该是中等难度...
```
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || head.next == null || k == 1) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode travel = dummy;
        while (true) {
            if (!checkLength(travel, k)) return dummy.next;
            travel = reverse(travel, k);
        }
    }
    private ListNode reverse(ListNode dummy, int k) {
        ListNode head = dummy.next;
        ListNode pre = dummy.next;
        ListNode next = pre.next;
        for (int i = 2; i <= k; ++i) {
            ListNode tmp = next.next;
            next.next = pre;
            pre = next;
            next = tmp;
        }
        dummy.next = pre;
        head.next = next;
        return head;
    }
    private boolean checkLength(ListNode dummy, int k) {
        if (dummy == null) return false;
        int cnt = 0;
        ListNode travel = dummy.next;
        while (travel != null && ++cnt < k) travel = travel.next;
        return cnt >= k;
    }
}
```