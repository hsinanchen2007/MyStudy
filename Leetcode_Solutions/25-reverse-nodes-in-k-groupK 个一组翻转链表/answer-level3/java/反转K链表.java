### 解题思路
此处撰写解题思路

记录两个指针，一个扫描指针end，找到第k个位置，一个前置指针pre, 单独写一个函数反转 pre->end之间的链表，
反转后重新建立好关系，两个指针 pre\end 都需要重新置位

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
        ListNode dump = new ListNode(0);
        dump.next = head;
        ListNode pre = dump;
        ListNode end = dump;
        while(end != null) {
            for (int i = 0; i < k && end != null; i++) {
                end = end.next;
            }
            if (end == null) {
                break;
            }
            ListNode start = pre.next;
            ListNode next = end.next;
            end.next = null;
            pre.next = reverseNode(start);
            start.next = next;
            pre = start;
            end = start;
        }
        return dump.next;
    }

    public ListNode reverseNode(ListNode head) {
        ListNode pre = null;
        ListNode curl = head;
        while(curl != null) {
            ListNode node = curl.next;
            curl.next = pre;
            pre = curl;
            curl = node;
        }
        return pre;
    }
}
```