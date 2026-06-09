### 解题思路
递归。一直调用方法拿到最后一个节点，它就是头节点，让它一层一层返回来。
每返回一层，当前方法栈能拿到3个节点：分别是当前遍历到的节点、next节点、以及将会成为结果头节点的节点。
此时，让next节点指向当前遍历到的节点即可，然后原封不动返回头结点给上一个方法调用。

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
        if (head == null || head.next == null) return head;
        ListNode newHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
    }
}
```