```
class Solution {
    public ListNode partition(ListNode head, int x) {
        if(head==null)
            return head;
        //一次遍历原链表
        ListNode lesshead = new ListNode(-1);
        ListNode less = lesshead;
        ListNode morehead = new ListNode(-1);
        ListNode more = morehead;
        while(head!=null){
            if(head.val<x){
                less.next = new ListNode(head.val);
                less = less.next;
            }else{
                more.next = new ListNode(head.val);
                more = more.next;
            }
            head = head.next;
        }
        less.next = morehead.next;
        return lesshead.next;
    }
}
```
