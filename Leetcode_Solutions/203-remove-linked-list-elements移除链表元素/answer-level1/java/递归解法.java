### 解题思路

**递归解法**

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
    public ListNode removeElements(ListNode head, int val) {
        if(head == null)
            return null;
        head.next = removeElements(head.next,val);
        return head.val == val ? head.next:head;
    }
}
```