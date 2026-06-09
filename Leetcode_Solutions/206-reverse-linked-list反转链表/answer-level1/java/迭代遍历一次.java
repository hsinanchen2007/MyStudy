### 解题思路
迭代遍历一次。过程中用两个指针，指向前一个，和正在遍历那个，加上正在遍历的节点是可以拿到下一个节点的，便具足前中后3个节点，可以重建指向关系，并更新指针。

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
         ListNode previous = null;
        ListNode current = head;
        ListNode next = null;
        while (current != null) {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
}
```