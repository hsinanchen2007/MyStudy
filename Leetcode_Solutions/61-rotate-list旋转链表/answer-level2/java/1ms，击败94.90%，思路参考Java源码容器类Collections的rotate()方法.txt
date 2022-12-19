### 解题思路
根据k找到分割点，分为A、B两个子列表，翻转A，翻转B，连接AB，再翻转整个链表，经过三次翻转可获得答案
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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        int length = 0;
        ListNode cur = head;
        // 计算链表长度并记录下尾节点
        ListNode rear = cur;
        while (cur != null) {
            rear = cur;
            cur = cur.next;
            length++;
        }
        if (k % length == 0) {
            return head;
        }
        int index =length - k % length;
        // B的头节点
        cur = head;
        // A的尾节点
        ListNode prev = cur;
        while (index > 0) {
            prev = cur;
            cur = cur.next;
            index--;
        }
        // 断开A和B
        prev.next = null;
        reverse(head);
        reverse(cur);
        // 连接A和B
        head.next = rear;
        reverse(prev);
        return cur;
    }
    public ListNode reverse(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode prev = head;
        ListNode cur = head.next;
        while (cur != null) {
            ListNode temp = cur.next;
            cur.next = prev;
            prev = cur;
            cur = temp;
        }
        head.next = null;
        return prev;
    }
}
```