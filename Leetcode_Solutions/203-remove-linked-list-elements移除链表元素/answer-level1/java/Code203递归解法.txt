### 解题思路
递归解法

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

        //result代表head之外，后面已经被删除val节点后剩余的链表
        ListNode result = removeElements(head.next, val);

        if (head.val == val) {
            return result;
        }
        else {
            head.next = result;
            return head;
        }
    }
}
```