### 解题思路
如果下一个节点的val等于现在的节点的val，那么就直接略过下一个节点。

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
    public ListNode deleteDuplicates(ListNode head) {
        // 如果下一个节点的val等于现在的节点的val，那么就直接略过下一个节点
        ListNode current = head;
        while(current != null && current.next != null){
            if (current.val == current.next.val){
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return head;
    }
}
```