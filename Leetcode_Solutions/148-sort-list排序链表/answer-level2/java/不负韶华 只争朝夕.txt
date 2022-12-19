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
        if (head == null || head.next ==null)
            return head ;
        
        ListNode dummy = new ListNode(-1) ;
        dummy.next = head ;
        ListNode curNode = head ;
        ListNode tail = dummy ;
        int length = 0;
        while (curNode!=null) {
            curNode = curNode.next ;
            length ++ ;
        }

        for (int i=1 ;i < length ; i <<= 1) {
            curNode = dummy.next ;
            tail =  dummy ;
            while (curNode != null ){
                ListNode left = curNode ;
                ListNode right = cut(curNode,i) ;
                curNode = cut(right,i) ;
                tail.next = mergeTwoLists(left,right) ;
                while (tail.next != null) {
                    tail = tail.next ;
                }
            }
        }
        return dummy.next ;
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode ret = new ListNode(-1) ;
        ListNode retCur = ret ;
        ListNode curL1Node = l1 ;
        ListNode curL2Node = l2 ;
        while(curL1Node != null && curL2Node != null) {
            if (curL1Node.val <= curL2Node.val) {
                retCur.next = curL1Node ;
                curL1Node = curL1Node.next ;
            } else {
                retCur.next = curL2Node ;
                curL2Node = curL2Node.next ;
            }
            retCur.next.next = null ;
            retCur = retCur.next ;
        }
        if (curL1Node != null) {
            retCur.next = curL1Node ;
        }
        if (curL2Node != null) {
            retCur.next = curL2Node ;
        }
        return ret.next ;
    }

    public ListNode cut(ListNode l , int n ) {
        ListNode curNode = l ;
        ListNode preCurNode = null ;
        while (curNode!= null && n>0) {
            if (n==1)
                preCurNode = curNode ;
            curNode = curNode.next ;
            n -- ;
        }
        if (preCurNode!=null)
            preCurNode.next = null ;
        return curNode ;
    }
}
```
