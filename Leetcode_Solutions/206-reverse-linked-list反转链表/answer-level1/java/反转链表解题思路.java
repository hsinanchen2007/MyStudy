### 解题思路

我们新的头节点记为newHead，其值应该是翻转以head.next为头节点的链表的结果。同时把head放在head.next的后面，并令head.next为null，这样我们就把head元素放在了新链表的末尾。

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
        if(head == null || head.next == null){
            return head;
        }
        ListNode newHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
      

    }
}
```
