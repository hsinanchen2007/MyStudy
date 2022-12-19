```
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode fir = new ListNode(-1);
        //确保head不是要删除的值
        while(head.val==val){
            head=head.next;
        }
        fir.next = head;
        while(head.next != null){
            //要删除的值不在头尾
            if(head.next.val==val && head.next.next!=null){
                head.next=head.next.next;
            //要删除的值在尾部
            }else if(head.next.val==val && head.next.next==null){
                head.next=null;
                return fir.next;
            }
            head=head.next;
        }
        return fir.next;
    }
}
```
