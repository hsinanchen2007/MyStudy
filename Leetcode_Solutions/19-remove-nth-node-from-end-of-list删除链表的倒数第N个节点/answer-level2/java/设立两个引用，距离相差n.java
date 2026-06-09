### 解题思路
加入头节点，确保删除操作的普适性。

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy;
        int basic = 0;
        while (head != null){
            head = head.next;
            basic++;
            if (basic > n){
                pre = pre.next;
            }
        }
        pre.next = pre.next.next;
        return dummy.next;
    }
}
```