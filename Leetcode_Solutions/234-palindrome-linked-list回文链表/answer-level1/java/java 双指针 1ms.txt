### 解题思路
参照官方解题思路，写出代码
1.通过fast和slow双指针，找到链表的中间
2.无论奇数还是偶数，slow都算到前半串
3.对slow.next进行链表的反转，进行比较两个串
4.比较完成后，再将后半串反转回去，接好
5.返回比较的最终结果

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
        if(head == null || head.next==null) return true;
        ListNode slow = firstOfHalf(head);
        ListNode fast = reverseList(slow.next);
        ListNode header = head;
        while(fast!=null && header!=null ){
            if(fast.val != header.val){
                return false;
            }
            fast = fast.next;
            header = header.next;
        }
        slow.next = reverseList(fast);
        return true;
    }
    public ListNode reverseList(ListNode head){
        if(head == null || head.next==null) return head;
        ListNode curr = head;
        ListNode prev = null;
        while(curr!=null){
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    public ListNode firstOfHalf(ListNode head){
        if(head == null) return null;
        ListNode fast = head;
        ListNode slow = head;
        while(fast!=null && fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
}
```