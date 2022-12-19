### 解题思路
采用三个指针变量，`curr`用于保存当前遍历到的结点，`prev`用于保存当前结点的前一个结点(反转后成为当前结点的下一结点)，`next`用于保存当前结点的下一个结点(反转后成为当前结点的前一个结点)。

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
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}
```