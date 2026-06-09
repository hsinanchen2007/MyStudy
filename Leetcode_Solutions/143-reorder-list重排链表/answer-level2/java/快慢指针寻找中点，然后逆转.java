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

    /**
     * 1、使用快慢指针寻找链表中间点
     * 2、逆转后半段的链表
     * 3、然后从前后同时遍历链表，重拍链表
     * @param head
     */
    public void reorderList(ListNode head) {
        if (head == null) {
            return;
        }
        ListNode fast = new ListNode(-1);
        fast.next = head;
        ListNode slow = fast;
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
            if (fast.next == null) {
                break;
            }
            fast = fast.next;
        }
        ListNode front = slow;
        ListNode rear = slow.next;
        front.next = null;
        while (rear != null) {
            slow = rear;
            rear = rear.next;
            slow.next = front;
            front = slow;
        }
        front = head;
        rear = slow;
        ListNode front2 = front.next;
        ListNode rear2 = rear.next;
        while (front2 != null && rear2 != null) {
            front.next = rear;
            rear.next = front2;
            front = front2;
            rear = rear2;
            front2 = front2.next;
            rear2 = rear2.next;
        }
        if (rear2 != null) {
            front.next = rear;
            rear.next = front2;
        }
    }
}
```