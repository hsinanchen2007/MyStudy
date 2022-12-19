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
        if (head == null){
            return null;
        }
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;
        while (head != null){
            ListNode cache = head;
            ListNode next = head;
            while (head.next != null && head.next.val == cache.val){
                next = head.next.next;
                head = head.next;
            }
            pre.next = next;
            if (head != next){
                head = next;
                continue;
            }
            pre = head;
            head = head.next;
        }
        return dummy.next;
    }
}
```