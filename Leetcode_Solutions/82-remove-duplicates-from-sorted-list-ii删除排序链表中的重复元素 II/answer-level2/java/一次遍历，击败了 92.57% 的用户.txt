```
class Solution {
     public ListNode deleteDuplicates(ListNode head) {
        //确保前两个节点存在
        if(head==null)return null;
        if(head.next==null)return head;
        if(head.next.next==null&&head.val==head.next.val)return null;

        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode pre = dummyHead;
        ListNode cur = dummyHead.next;
        ListNode last = dummyHead.next.next;

        while(last!=null){
            if(cur.val!=last.val){
                last=last.next;
                cur=cur.next;
                pre=pre.next;
            }
            else{
                while(last!=null){
                    if(cur.val!=last.val){
                        cur=last;
                        last=last.next;
                        pre.next=cur;
                        break;
                    }
                    last=last.next;
                }
            }
        }
        if (pre.next.next!=null)pre.next=null;//避免[1,2,2]这种情况，理论上pre/cur/next最终一定是在最后三个位置的节点上的
        return dummyHead.next;

    }
}
```
