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
    public ListNode deleteNode(ListNode head, int val) {
      ListNode r = new ListNode(-1);
        r.next = head;
        ListNode slow = r;
        ListNode fast = r.next;
        while (fast != null){
            if(fast.val == val){
                slow.next = fast.next;
                break;
            }
            fast = fast.next;
            slow = slow.next;
        }
        return r.next;
    }
}
```