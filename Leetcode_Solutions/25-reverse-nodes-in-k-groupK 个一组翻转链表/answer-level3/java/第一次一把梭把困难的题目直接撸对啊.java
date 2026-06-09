### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode fast = head;
        ListNode slow = head;
        ListNode newHead = new ListNode(0);
        ListNode tail = newHead;
        while (null != fast) {
            for (int i = 0; i < k-1; i++) {
                if (fast != null ) {
                    fast = fast.next;
                }else {
                    break;
                }
            }
            if (fast != null) {
                ListNode fastNext = fast.next;
                fast.next = null;
                tail.next = reverseList(slow);
                fast = slow = fastNext;
                while (tail.next != null) {
                    tail = tail.next;
                }
            }else {
                break;
            }
        }
        tail.next = slow;
        return newHead.next;
    }
    // 翻转单链表
    public ListNode reverseList(ListNode head) {
        ListNode newHead = new ListNode(0);
        ListNode fast = head.next;
        ListNode slow = head;
        while (slow != null) {
            ListNode tmp = newHead.next;
            newHead.next = slow;
            slow.next = tmp;
            slow = fast;
            if (fast != null) {
                fast = fast.next;
            }
        }
        return newHead.next;
    }
}
```