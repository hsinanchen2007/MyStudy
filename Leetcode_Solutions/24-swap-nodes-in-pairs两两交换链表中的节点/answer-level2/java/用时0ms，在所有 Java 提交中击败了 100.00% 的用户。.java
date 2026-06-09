### 解题思路
递归，这是我第一次在不看题解的情况下，独立使用递归完成了一道中等难度的题。我一直都觉得递归很难理解。真的很难~

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
    public ListNode swapPairs(ListNode head) {
        ListNode p = head;
        return swapPair(p);
    }

    public ListNode swapPair (ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode temp = head.next;
        head.next = temp.next;
        temp.next = head;
        head = temp;
        head.next.next = swapPair(head.next.next);
        return head;
    }
}
```