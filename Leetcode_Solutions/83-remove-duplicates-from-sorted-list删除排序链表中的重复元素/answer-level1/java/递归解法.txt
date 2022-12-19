```class Solution {
    public ListNode deleteDuplicates(ListNode head) {
       
        if(head == null || head.next == null)
            return head;
        ListNode headNext = deleteDuplicates(head.next);
        if(head.val == headNext.val)                          
            head.next = headNext.next;
        return head;
    }
}
