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
    public ListNode deleteDuplicates(ListNode head){

        if (head == null)
            return null;
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode pre = dummyHead;
        ListNode cur = head;
        while(cur.next != null){
            ListNode next = cur.next;
            if (cur.val == next.val) {
                while ( next.next != null && next.next.val == cur.val) {
                    next = next.next;
                }
                pre.next = next.next;
                cur = pre.next;
                if (cur == null)
                    break;
                next = cur.next;
            }
            else {
                pre = cur;
                cur = next;
                next = cur.next;
            }
        }
        return dummyHead.next;
    }
}
```