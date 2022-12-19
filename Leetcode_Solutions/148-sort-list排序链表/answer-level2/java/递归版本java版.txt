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
    public ListNode sortList(ListNode head) {
        if(null==head || head.next==null) return head;
        return mergeSort(head);
    }

    private ListNode mergeSort(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode midNode = getMidNode(head);
        ListNode temp = midNode.next;
        midNode.next = null;
        ListNode h1 = mergeSort(head);
        ListNode h2 = mergeSort(temp);
        ListNode dummy = new ListNode(0);
        ListNode pre = dummy;
        while(h1!=null && h2!=null) {
            if(h1.val < h2.val){
                pre.next = h1;
                h1 = h1.next;
                pre = pre.next;
            }else {
                pre.next = h2;
                h2 = h2.next;
                pre = pre.next;
            }
        }
        pre.next = h1!=null ? h1:h2;
        return dummy.next;
    }
    private ListNode getMidNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null) {
            fast = fast.next;
            if(fast==null || fast.next==null) {
                return slow;
            }
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }
}
```
