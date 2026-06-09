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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
         int jw = 0;
        ListNode result = null;
        ListNode head = null;
        while ((l1 != null || l2 != null) || jw > 0) {
            int val = 0;
            if(l1 != null) {
                val += l1.val;
                l1 = l1.next;
            }
            if(l2 != null) {
                val += l2.val;
                l2 = l2.next;
            }
            ListNode listNode = new ListNode((val + jw) % 10);
            if(result == null) {
                result = listNode;
                head = listNode;
            }else {
                result.next = listNode;
                result = result.next;
            }
            jw = (jw + val) / 10;
        }
        return head;
    }
}
```