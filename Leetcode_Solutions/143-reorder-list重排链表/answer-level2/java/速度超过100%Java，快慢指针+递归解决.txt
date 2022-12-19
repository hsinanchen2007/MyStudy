### 解题思路
![143.重排链表.png](https://pic.leetcode-cn.com/c399ff830975c0b883be7dd3396d2c34fba49c9d23d1bee6e0bad8f47ef9bac3-143.%E9%87%8D%E6%8E%92%E9%93%BE%E8%A1%A8.png)
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

    ListNode newHead = null;

    public void reorderList(ListNode head) {
        if(head == null) return;
        //快慢指针找中间节点

        ListNode fast = head.next;
        ListNode slow = head;

        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        //"废物"利用，将fast重新拿回来用，用于指向被截断的后半截链表
        fast = slow.next;
        slow.next = null;

        newHead = head;
        helper(fast, null);

    }

    //helper的用处很简单，将被截断的链表通过递归从尾部截取节点，将之放入“前半段链表”中的指定位置
    private void helper(ListNode lower, ListNode preNode) {
        if(lower == null) return;
        helper(lower.next, lower);

        if(preNode != null) {
            preNode.next = null;
            lower.next = newHead.next;
            newHead.next = lower;
            newHead = newHead.next.next;
        }
        else {
            lower.next = newHead.next;
            newHead.next = lower;
        }
    }
}
```