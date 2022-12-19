### 解题思路

解法思路还是比较简单的，对于中间的节点通过循环删除，对于头节点，则通过递归方式进行删除。

![image.png](https://pic.leetcode-cn.com/5f0dc16e0c5687c4c8d28d7d0e83618852fc867e3e13e158f52ff79f3b717119-image.png)


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
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) {
            return null;
        }
        if (head.val == val) {
            return removeElements(head.next, val);
        }
        ListNode n = head;
        while (n.next != null) {
            if (n.next.val == val) {
                n.next = n.next.next;
            } else {
                n = n.next;
            }
        }
        return head;
    }
}
```