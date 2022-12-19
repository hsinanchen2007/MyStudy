### 解题思路

一个指针指向当前节点，一个指向原来链表指针的下一个节点

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
        ListNode latter = head, former = null;
        while (latter != null) {
            ListNode node = latter.next;
            latter.next = former;
            former = latter;
            latter = node;
        }
        return former;
    }
}
```