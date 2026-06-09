### 解题思路
单向链表
遍历链表，如果val为头节点直接返回head.next。
若当前节点不为空且当前节点的值不等于val，继续下一个节点。直至cur == null说明链表中没有val值的节点，返回原来的链表的头节点，删除失败。
否则直接上一个节点的下一个指向当前待删除节点的下一个，实现删除目标节点。

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
    public ListNode deleteNode(ListNode head, int val) {
        if(head == null) return null; 
        if(head.val == val) return head.next;
        ListNode pre = head, cur = head.next;
        while(cur != null && cur.val != val) {
            pre = cur;
            cur = cur.next;
        }
        if(cur == null) return head;
        pre.next = cur.next;
        return head;

    }
}
```