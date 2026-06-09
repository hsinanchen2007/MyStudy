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
   public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null){
            return true;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next !=null){
            head = head.next;
            fast = fast.next.next;
        }
        fast = head.next;
        head.next = null;
 
        ListNode refast = null;
        while (fast!= null){
            ListNode next = fast.next;
            fast.next = refast;
            refast = fast;
            fast = next;
        }
        while (slow != null && refast != null){
            if (slow.val != refast.val){
                return false;
            }
            slow = slow.next;
            refast = refast.next;
        }
        return true;
    }
}
```