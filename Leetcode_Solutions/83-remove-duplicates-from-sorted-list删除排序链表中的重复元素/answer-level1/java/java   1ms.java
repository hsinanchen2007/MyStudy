### 解题思路
此处撰写解题思路

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
        if(head == null) {
            return null;
        }
        ListNode node = head;
        ListNode cur = head;
        while(node != null && node.next != null) {
            if(node.val == node.next.val) {
                while(node.next != null && node.val == node.next.val) {
                    node = node.next;
                }
                cur.next = node.next;
                node = node.next;
                cur = cur.next;
            }else {
                node = node.next;
                cur = cur.next;
            }
        }
        return head;
    }
}
```