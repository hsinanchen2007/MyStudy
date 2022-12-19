### 解题思路
自定义头前节点来保证后续节点的判断，不需要特殊处理头节点

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
    public ListNode swapPairs(ListNode head) {
        ListNode node0 = new ListNode(0);
        node0.next = head;
        ListNode cur = node0;
        while (cur.next != null && cur.next.next != null) {
            ListNode n1 = cur.next;
            ListNode n2 = cur.next.next;
            n1.next = n2.next;
            cur.next = n2;
            n2.next = n1;
            cur = n1;
        }
        return node0.next;
    }
}
```