手动实现一下整个过程，就会明白这个流程。
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
    public ListNode reverse(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode pre = null;
        while(head != null) {
            ListNode p = head.next;
            head.next = pre;
            pre = head;
            head = p;
        }
        return pre;
    }
    public void reorderList(ListNode head) {//void类型
        if(head == null ||head.next == null) return;
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode tmp = slow.next;
        slow.next = null;
        ListNode tmp1 = reverse(tmp);

        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        while(head != null && tmp1 != null) {
            cur.next = head;
            head = head.next;
            cur = cur.next;
            cur.next = tmp1;
            tmp1 = tmp1.next;
            cur = cur.next;
        }
        cur.next = head;

    }
}
```
