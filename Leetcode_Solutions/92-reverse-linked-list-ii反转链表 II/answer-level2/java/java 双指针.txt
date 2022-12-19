### 解题思路
1.prev走到反转的前一结点，记录n1_start和n2_start
2.再走一步，prev走到反转的那一结点
3.将链表段进行反转
4.n1_start和反转后的链表段和n2_start和剩余的链表段连接起来
5.返回链表

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0);
        ListNode prev  = dummy;
        prev.next = head; 
        ListNode curr = head;
        for(int i=1;i<m;i++){
            prev = prev.next;
            curr = curr.next;
        }
        ListNode n1_start = prev;
        ListNode n2_start = prev.next;

        prev = prev.next;
        curr = curr.next;
        for(int i=0;i<n-m;i++){
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        n1_start.next = prev;
        n2_start.next = curr;
        return dummy.next;
        
    }
}
```