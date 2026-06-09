class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode prevHeader = new ListNode(-1);
        ListNode prev = prevHeader;

        while (l1 != null && l2 != null) {
            int tempValue = l1.val + l2.val;
        
            if ( tempValue >= 10) {
                prev.next = new ListNode( tempValue -10);
                if (l1.next == null) {
                    l1.next = new ListNode(1);
                }else if( l2.next == null){
                    l2.next = new ListNode(1);
                }
                else{
                    l1.next.val = l1.next.val + 1;
                }
                
            }else{
                prev.next = new ListNode( tempValue);           }

            l1 = l1.next;
            l2 = l2.next; 
            prev = prev.next;   
        }

        if (l1 != null) {
            prev.next = l1;
        }
        if(l2 != null) {
            prev.next = l2;
        }

    return prevHeader.next;
    }
}