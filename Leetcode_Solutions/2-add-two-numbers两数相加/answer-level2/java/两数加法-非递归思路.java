/**
 * 两个链表分别遍历一次
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        int sumVal = l1.val + l2.val;
        int gVal = sumVal % 10; //个位
        int sVal = sumVal / 10; //十位
        ListNode root = new ListNode(gVal);
        ListNode node = root;
     
        while(l1.next != null) {
            sumVal = l1.next.val;
            l1 = l1.next;
            if(l2.next != null) {
                sumVal += l2.next.val;
                l2 = l2.next;
            }
            sumVal += sVal; 
            gVal = sumVal % 10;
            sVal = sumVal / 10;
            node.next = new ListNode(gVal);
            node = node.next;
        }

        while(l2.next != null) {
            sumVal = l2.next.val;
            sumVal += sVal;
            gVal = sumVal % 10;
            sVal = sumVal / 10;
            l2 = l2.next;
            node.next = new ListNode(gVal);
            node = node.next;
        }

        if(sVal != 0){
            node.next = new ListNode(sVal);
            node = node.next;
        }

        return root;
    }
}