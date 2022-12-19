### 解题思路
此处撰写解题思路
1、查找从左到右第n个节点，如果刚好去除的是头结点，直接进行处理
2、一直遍历直到最后一个元素为空
3、进行节点删除操作
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next == null) return null;
        // 找到从左到右第n个节点
        ListNode p = head;
        ListNode nextN = head.next;
        while (n !=1) {
            nextN = nextN.next;
            n--;
        }
        if (nextN == null) {
            head = head.next;
            p = null;
            return head;
        }
        // 一直遍历直到最后一个元素为空
        while (nextN.next != null) {
            p = p.next;
            nextN = nextN.next;
        }
        // 进行删除操作
        p.next = p.next.next;
        return head;
    }
}
```