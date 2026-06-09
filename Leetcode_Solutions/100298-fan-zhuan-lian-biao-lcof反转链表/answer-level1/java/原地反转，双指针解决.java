### 复杂度分析
时间复杂度：O(n)
空间复杂度：O(1)

### 解题思路
记录反转结点的前驱与后继，循环执行 
node.next = pre;
pre = node;
node = next;

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
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode pre = null;
        ListNode node = head;
        ListNode next = node.next;
        while (node != null) {
            next = node.next;
            node.next = pre;
            pre = node;
            node = next;
        }
        return pre;
    }
}
```