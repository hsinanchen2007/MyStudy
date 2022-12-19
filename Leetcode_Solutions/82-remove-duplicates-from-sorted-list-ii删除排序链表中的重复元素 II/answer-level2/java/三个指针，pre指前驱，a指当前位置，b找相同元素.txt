
```java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode head_1 = new ListNode(-1);
        head_1.next = head;
        ListNode pre = head_1;
        while(pre.next!=null && pre.next.next!=null){
            ListNode a = pre.next;
            ListNode b = pre.next.next;
            if(b.val == a.val){
                while(b != null && b.val == a.val){
                    b = b.next;
                }
                pre.next = b;
            }
            else pre = pre.next;
        }
        return head_1.next; 
    }
} 
```



