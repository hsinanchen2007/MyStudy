咱也来一个 归并排序版本的Java代码，具体思路和题解中的Python代码是一样的，使用快慢指针找到，链表中点，递归的对两边进行sortList， 最后merge

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode preMid = getMidNode(head);
        ListNode mid = preMid.next;
        // 断开连接
        preMid.next = null;
        return mergeList(sortList(head), sortList(mid));
    }
    private ListNode getMidNode(final ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    private ListNode mergeList(final ListNode head1, final ListNode head2) {
        ListNode fakeHead = new ListNode(-1);
        ListNode head = fakeHead;
        ListNode cur1 = head1;
        ListNode cur2 = head2;
        while (cur1 != null && cur2 != null) {
            if (cur1.val < cur2.val) {
                head.next = cur1;
                cur1 = cur1.next;
            } else {
                head.next = cur2;
                cur2 = cur2.next;
            }
            head = head.next;
        }
        if (cur1 != null) {
            head.next = cur1;
        }
        if (cur2 != null) {
            head.next = cur2;
        }
        return fakeHead.next;
    }
}
```
