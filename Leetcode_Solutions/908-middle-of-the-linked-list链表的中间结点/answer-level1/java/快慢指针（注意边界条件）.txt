### 解题思路
快慢指针中，注意边界条件 null != fastNode && null != slowNode&& fastNode.next != null，第三个条件是为了防止链表过短造成空指针异常

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
    public ListNode middleNode(ListNode head) {
                 ListNode fastNode = head;
        ListNode slowNode = head;
        while (null != fastNode && null != slowNode&& fastNode.next != null) {
            slowNode = slowNode.next;
            fastNode = fastNode.next.next;
        }

        return slowNode;
    }
}
```