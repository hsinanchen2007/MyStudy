### 解题思路
/**
 * 思路
 * 1.将两个链表反转
 * 2.反转后每位相加
 * 3.将所得链表反转
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1==null) return l2;
        if (l2==null) return l1; 
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        ListNode l1Rev = reverseList(l1);
        ListNode l2Rev = reverseList(l2);
        int sum = 0;
        while(l1Rev != null || l2Rev != null){
            int l1v = (l1Rev == null)?0:l1Rev.val;
            int l2V = (l2Rev == null)?0:l2Rev.val;
            sum = sum + l1v + l2V;
            curr.next = new ListNode(sum%10);
            sum = sum/10;

            l1Rev = (l1Rev==null)?null:l1Rev.next;
            l2Rev = (l2Rev==null)?null:l2Rev.next;
            curr = curr.next;
        }
        if(sum!=0)
            curr.next = new ListNode(sum);
        return reverseList(dummy.next);
    }
    public ListNode reverseList(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode prev = null;
        ListNode curr = head;
        while(curr != null){
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
}
```