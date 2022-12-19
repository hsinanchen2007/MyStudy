### 解题思路
/**
 * 快慢双指针
 * 快指针先走k步，然后快慢指针一起走
 * 快指针为null时，慢指针就走到倒数第k个  
 */

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode slow = head, fast = head;
        for(int i = 0; i<k;i++)
            fast = fast.next;
        while(fast!=null){
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }
}
```