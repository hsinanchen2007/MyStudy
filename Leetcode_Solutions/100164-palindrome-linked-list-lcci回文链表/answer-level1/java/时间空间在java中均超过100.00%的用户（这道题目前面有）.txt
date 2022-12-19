### 解题思路
1.找到链表的中间，如果fast=head.next，最终slow指向中间偏左（偶数情况下），
如果fast=head,slow指向中间偏右（偶数情况下），对于奇数没有差别
2.将slow作为前半部分，slow.next作为后半部分，后半部分反转
3.将前半部分与反转后的后半部分比较，
4.再将后半串反转回来，slow.next = reverlist(revfast)，接好，不破坏原先链表
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
        if(head == null || head.next == null) return true;
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast != null && fast.next!= null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode revfast = reverseList(slow.next);
        while(revfast!=null){
            if(head.val != revfast.val)
                return false;
            revfast = revfast.next;
            head = head.next;
        }
        slow.next = reverseList(revfast);
        return true;
    }
    public ListNode reverseList(ListNode head){
        if(head == null || head.next == null ) return head;
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
}
```