class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null) return head;

        ListNode dump = new ListNode(0);
        dump.next = head;

        ListNode first = dump,end = head;
        while(end != null){
            if(end.next!=null && end.val == end.next.val){
                end = end.next;
                while(end.next != null && end.val == end.next.val){
                    end = end.next;
                }
               first.next = end.next;
               end = first.next;
            }else{
                first = end;
                end = end.next;
            }
        }
        return dump.next;
    }
}

