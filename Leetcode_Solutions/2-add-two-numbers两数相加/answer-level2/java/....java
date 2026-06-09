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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head1 = l1;
        ListNode head2 = l2;
        ListNode newHead = new ListNode(0);
        ListNode head3 = newHead;
         //进位预设
        boolean carry = false ;
        while (head1 != null || head2 != null ){
            int x = (head1 != null) ? head1.val : 0;
            int y = (head2 != null) ? head2.val : 0;
            int sum = carry ? (x + y + 1) : (x + y);
            //数值相加
            if (sum >= 10){
                sum -= 10;
                carry = true;
            } else {carry = false;//进位判断
            }
             
            head3.next = new ListNode(sum % 10);
            head3 = head3.next;
            if (head1 != null) head1 = head1.next;
            if (head2 != null) head2 = head2.next;
        }
        if (carry){
            head3.next = new ListNode(1);
        }
        return newHead.next;
        
    }
}
```