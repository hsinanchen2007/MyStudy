### 解题思路
思路：采用迭代的方式，首先确立两个节点：当前节点以及当前节点的上一节点，如果当前节点的`val`与需移除的`val`相等时，将当前节点移除，即将上一节点的下一节点指向当前节点的下一节点，当前节点置为当前节点的下一节点，这里有种临界情况：头节点的`val`就为需要排除的`val`，此时便将头节点向后移动至下一节点即可。`val`不相等的情况，就将上一节点置为当前节点，当前节点的下一节点置为当前节点即可。最后，返回头节点。
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
        ListNode current = head;
        ListNode prev = null;
        while(current != null) {
            if (current.val == val) {
                if (prev == null) {
                    current = current.next;
                    head = current;
                } else {
                    prev.next = current.next;
                    current = current.next;
                }
            } else {
                prev = current;
                current = current.next;
            }
        }

        return head;
    }
}
```