### 解题思路
此处撰写解题思路
删除倒数第n个，其实找到第n-1个。如果想通过一次遍历就找到，使用双指针，其中一个先遍历n+1次，然后两个链表再一起遍历，直到有一个节点为null。
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
        if (n < 0) {
            throw new IllegalArgumentException("n < 0");
        }
        ListNode target = new ListNode(0);
        target.next = head;
        ListNode first = target;
        ListNode second = target;
        for (int i = 0; i < n + 1; i++) {
            first = first.next;
        }
        while (first != null) {
            first = first.next;
            second = second.next;
        }
        second.next = second.next.next;
        return target.next;
    }
}
```