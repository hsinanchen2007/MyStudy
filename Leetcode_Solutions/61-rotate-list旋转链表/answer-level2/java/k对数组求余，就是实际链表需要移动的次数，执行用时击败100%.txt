### 解题思路
实际上不用移动k次就是得出结果，我们先遍历一次链表求出链表长度length，然后求出余数k%length,就是链表需要移动的次数。

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
        if (head == null || head.next == null) {
            return head;
        }
        ListNode testLength = head;
        int length = 1;
        while (testLength.next != null) {
            length++;
            testLength = testLength.next;
        }
        int moveCount = k%length;
        while (moveCount-- > 0) {
            ListNode preTail = head;
            while (preTail.next.next != null) {
                preTail = preTail.next;
            }
            preTail.next.next = head;
            head = preTail.next;
            preTail.next = null;
        }
        return head;
    }
}
```