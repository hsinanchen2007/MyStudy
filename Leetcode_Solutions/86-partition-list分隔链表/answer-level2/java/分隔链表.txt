分成两个链表，一个小于x，一个大于等于x；
进行拼接；
```
import java.util.*;
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode head1 = null;
        ListNode tail1 = null;
        ListNode head2 = null;
        ListNode tail2 = null;
        while(head != null) {
            ListNode next = head.next;
            if(head.val < x) {
                if(head1 == null) {
                    head1 = head;
                    tail1 = head;
                }else {
                    tail1.next = head;
                    tail1 = head;
                }
                tail1.next = null;
            }else {
                if(head2 == null) {
                    head2 = head;
                    tail2 = head;
                }else {
                    tail2.next = head;
                    tail2 = head;
                }
                tail2.next = null;
            }
            head = next;
        }
        if(head1 != null) {
            tail1.next = head2;
            return head1;
        }else return head2;
    }
}
```
