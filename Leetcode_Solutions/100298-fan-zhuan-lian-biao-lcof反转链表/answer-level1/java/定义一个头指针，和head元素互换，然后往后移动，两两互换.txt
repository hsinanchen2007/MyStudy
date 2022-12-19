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
    public ListNode reverseList(ListNode head) {
         ListNode pre = null;
         while(head != null){
             ListNode cur = head;
             head = head.next;
             cur.next = pre;
             pre = cur;
         }

         return pre;
    }
}
```