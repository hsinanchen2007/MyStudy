### 解题思路
从头节点的next指针开始反转，经过递归调用，最后一个节点反转后成为新的头节点，而头节点的next的next指针就指向了自己，此时，头结点的next指向已经无用，置空即可。

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
        if (head == null || head.next == null) {
            return head;
        }
        ListNode newHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
    }
}
```