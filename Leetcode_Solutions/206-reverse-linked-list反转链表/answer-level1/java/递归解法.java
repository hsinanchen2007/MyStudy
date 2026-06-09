### 解题思路
递归：从后往前递归去置换左右两边节点
1. 判断当前传入节点是否为空，如果为空直接返回；如果后继节点为空，则判断该链表已到尾部，返回该节点
2. 递归传递当前节点的后一位节点，使用节点存储返回的结果
3. 当前节点的后一位节点为返回的节点，使返回节点的后继节点变为当前节点，实现逆序
4. 当前节点的后一位置空，即变为新生成链表的头部

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
       //一直递归到链表尾部
        ListNode next = reverseList(head.next);
        //head为currentNode，当前节点的后继节点为next，
        head.next.next = head;
        head.next = null;
        return next;
    }
}
```