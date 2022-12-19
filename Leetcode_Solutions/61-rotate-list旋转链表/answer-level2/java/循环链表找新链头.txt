### 解题思路
假如链表是一个循环链，则每旋转1次，相当于让链头后退1步、等价于让链头前进length-1步（length为链表长度）。（k<=n时）旋转k次，链头前进length-k步。当k>n时，每旋转n次会回到原链头，所以等价于旋转k%n次。

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
        if (head == null) return null;

        // 建立循环链表，计算链长
        int length = 1;
        ListNode current = head;
        while (current.next != null) {
            current = current.next;
            length++;
        }
        current.next = head;

        // 计算新链头的前置元素（新链头位置是length-k，其前置是length-k-1）
        k = k % length;
        int newHeadPrevIndex = length - k - 1;
        ListNode newHeadPrev = head;
        for (int i = 0; i < newHeadPrevIndex; i++) newHeadPrev = newHeadPrev.next;

        // 从新链头的前置处断开，返回新链头
        ListNode newHead = newHeadPrev.next;
        newHeadPrev.next = null;
        return newHead;
    }
}
```