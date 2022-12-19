### 解题思路
此处撰写解题思路
递归算法，从后面往前反转。
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
        ListNode current = head;
        if(current == null){
            return current;
        }
        ListNode next = current.next;
        if(next == null){
            return current;
        }
        ListNode tail = swapPair(next.next);
        next.next = current;
        current.next = tail;
        return next;
    }
}
```