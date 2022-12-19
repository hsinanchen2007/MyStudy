```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
// 如果链表长度 <=1，则直接返回 true
// 先找到链表的中点（快慢指针）
// 再以中点为起点，将后面链表翻转（迭代、遍历）
// 最后分别以头结点和中点为起点，向后遍历，比较值是否相等，如果出现不等，则不是回文链表
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        // 找到链表的中点
        ListNode mid = findMid(head);
        // 翻转中点后的链表
        mid = reverseList(mid);
        // 比较两段链表
        while (mid != null) {
            if (head.val != mid.val) {
                return false;
            }
            head = head.next;
            mid = mid.next;
        }
        return true;
    }
    // 翻转链表（迭代、递归）
    private ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    // 找到链表的中间节点    
    private ListNode findMid(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
```
