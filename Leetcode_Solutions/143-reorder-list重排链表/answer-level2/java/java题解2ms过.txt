思路比较简单，直接贴代码了，应该都能读懂
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
    public void reorderList(ListNode head) {
        if(head==null || head.next==null) return;
        ListNode midNode = getMidNode(head);
        ListNode list2 = reverseList(midNode.next);
        ListNode list1 = head;
        midNode.next = null;
        while(list2!=null) {
            ListNode post = list1.next;
            ListNode post2 = list2.next;
            list1.next = list2;
            list2.next = post;
            list1 = post;
            list2 = post2;
        }
        return;
    }
    private ListNode getMidNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null && fast.next!=null) {
            fast = fast.next.next;
            if(fast==null) {
                return slow;
            }
            slow = slow.next;
        }
        return slow;
    }

    private ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode current = head;
        ListNode post = null;
        while(current!=null) {
            post = current.next;
            current.next = pre;
            pre = current;
            current = post;
        }
        return pre;
    }
}
```
