```
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
        if (head == null || head.next == null) {
            return true;
        }
        
        
        ListNode fast = head;
        ListNode slow = head;
        ListNode pre = null;
        
        while(fast != null && fast.next != null) {
            fast = fast.next.next; // 快指针移动两步
            
            // 反转
            ListNode next = slow.next;
            slow.next = pre;
            pre = slow;
            
            slow = next; // 慢指针移动一步
        }
        
        ListNode p1 = pre;
        ListNode p2 = slow;
        
        p2 = fast != null ? slow.next : slow; // 奇数节点的时候，把中间的那个节点忽略
        
        while(p1 != null && p2 != null) {
            if (p1.val != p2.val) {
                return false;
            }
            p1 = p1.next;
            p2 = p2.next;
        }
        
        return true;
    }
}
```