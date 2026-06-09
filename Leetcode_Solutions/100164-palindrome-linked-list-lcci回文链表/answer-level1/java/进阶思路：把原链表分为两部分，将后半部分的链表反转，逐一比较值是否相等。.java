进阶解法：把原链表分为两部分，将后半部分的链表反转，逐一比较值是否相等。
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
        //进阶
        //思路：把链表分为两部分，反转后半部分的链表，然后一一比较值是否相等
        //如果链表中没有元素 || 只有一个元素，那么返回True
        if (head == null || head.next == null)
            return true;
        
        //找到中间节点，slow，注意pre.next=null是将链表截断成两部分
        ListNode pre = head;
        ListNode slow = pre.next;
        ListNode fast = slow.next;
        
        while (fast != null && fast.next != null) {
            pre = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        if (pre != null)
            pre.next = null;
        //反转后半部分链表
        pre = null;
        while (slow != null) {
            ListNode tempNode = slow.next;
            slow.next = pre;
            pre = slow;
            slow = tempNode;
        }
        //注意这个条件 pre != null && head != null
        //设想一个情况，链表节点有奇数个，那么肯定有一部分的链表比另一部分的链表多一个节点
        //但是其实我们不必关注多出的这个节点。
        //eg:1->2->5->2->1。前半部分链表：1->2。后半部分(未反转)：5->2->1;后半部分(反转后)：1->2->5。
        //可以看到，最后的一个节点其实是不用去比较的，因为这个节点刚好是原链表最中间的那个节点。
        while (pre != null && head != null) {
            if (pre.val != head.val)
                return false;
            pre = pre.next;
            head = head.next;
        }
        
        return true;  
    }
    
}
```
