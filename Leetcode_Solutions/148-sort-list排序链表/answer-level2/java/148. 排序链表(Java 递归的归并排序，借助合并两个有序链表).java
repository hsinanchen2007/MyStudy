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
    // 148 归并排序
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        // 走一步，走两步，将链表cut成左右两部分
        ListNode pPre = head;
        ListNode p = head.next;
        ListNode q = head.next.next;
        while (p != null && q != null){
            ListNode pNext = p.next;
            ListNode qNext = q.next;
            if(qNext == null){
                break;
            }
            pPre = p;
            p = pNext;
            q = qNext.next;
        }

        ListNode n1 = head;
        ListNode n2 = pPre.next;
        pPre.next = null;
        ListNode leftSort = sortList(n1);
        ListNode rightSort = sortList(n2);
        return mergeTwoLists(leftSort, rightSort);
    }
    // 21 合并两个有序链表
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode node = null;
        ListNode nodeTail = null;
        ListNode p = l1;
        ListNode q = l2;
        while (p != null && q != null){
            if(p.val < q.val){
                ListNode pNext = p.next;
                if(node == null){
                    node = p;
                    nodeTail = p;
                }else {
                    nodeTail.next = p;
                    nodeTail = p;
                }
                nodeTail.next = null;
                p = pNext;
            }else{
                ListNode qNext = q.next;
                if(node == null){
                    node = q;
                    nodeTail = q;
                }else {
                    nodeTail.next = q;
                    nodeTail = q;
                }
                nodeTail.next = null;
                q = qNext;
            }
        }
        while (p != null){
            ListNode pNext = p.next;
            if(node == null){
                node = p;
                nodeTail = p;
            }else {
                nodeTail.next = p;
                nodeTail = p;
            }
            nodeTail.next = null;
            p = pNext;
        }
        while (q != null){
            ListNode qNext = q.next;
            if(node == null){
                node = q;
                nodeTail = q;
            }else {
                nodeTail.next = q;
                nodeTail = q;
            }
            nodeTail.next = null;
            q = qNext;
        }
        return node;
    }
}
```