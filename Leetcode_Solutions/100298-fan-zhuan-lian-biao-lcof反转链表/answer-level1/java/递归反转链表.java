### 解题思路
此处撰写解题思路
递归思路，递归出口是当head为null或者head.next为null，因此，递归的时候应该是从后往前将链表反转。
递归出口： if(head == null || head.next == null)
            return head;
递归操作： 需要额外的节点保存头节点ListNode node = reverseList(head.next)，当找到递归出口时，node为反转链表的头节点，head.next为node因此，head.next.next = head;即在递归过程中head是变动的，使用head进行反转即可。
返回操作： 返回头节点
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
        if(head == null || head.next == null)
            return head;
        ListNode node = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return node;
    }
}
```