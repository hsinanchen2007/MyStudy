### 解题思路
1.找到链表的尾节点和链表包含节点数
2.向右移k位等价于将节点末尾至倒数第k个节点子链表截取并平移至原链表头节点之前
3.注意k大于等于节点数的情况。

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
    public ListNode rotateRight(ListNode head, int k) {
        
        
        
        // 单一节点或空节点是两种特殊清况
        if (head == null || head.next == null)
            return head;
        ListNode tail = head;
        int size = 1;
        // 找到链表的节点个数和尾节点
        while (tail.next != null) {
            size++;
            tail = tail.next;
        }
        // 原链表成环
        tail.next = head;
        int count = size - (k % size);
        ListNode newTail = head;
        // 找到新链表的尾节点
        for (; count > 1; count --) {
            newTail = newTail.next;
        }
        // 新链表头节点等于新链表尾节点的后继节点
        // 新链表尾节点的后继节点为null
        head = newTail.next;
        newTail.next = null;
        return head;
    }
}
```