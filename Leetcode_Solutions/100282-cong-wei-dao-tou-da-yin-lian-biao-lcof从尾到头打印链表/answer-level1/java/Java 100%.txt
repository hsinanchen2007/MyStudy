翻转链表，并统计长度。

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
    public int[] reversePrint(ListNode head) {
        if (head == null)
            return new int[0];
        
        int len = 0;
        // 翻转链表，统计长度
        ListNode pre = null, cur = head;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
            len++;
        }
        
        int[] result = new int[len];
        int i = 0;
        while (pre != null) {
            result[i] = pre.val;
            pre = pre.next;
            i++;
        }
        return result;
    }
}
```