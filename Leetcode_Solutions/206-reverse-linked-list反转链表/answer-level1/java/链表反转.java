### 解题思路
此处撰写解题思路

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
         if (head == null)
            return head;
        ListNode pre = null; // 前一个节点
        ListNode cur = head; // 当前节点
        ListNode next = null; // 下一个节点
        while (cur != null){ // 移动的当前节点是否为空，为空，说明已经到达链表的结尾了 
            next = cur;      // 反转的下一节点为当前节点
            cur = next.next; // 当前节点后移一个节点
            next.next = pre; // 下一个节点为之前的前一节点
            pre = next;      // 之前的前一节点后移一个节点
        }
        return pre;
    }
}
```