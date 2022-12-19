由于头节点也可能是要被删除的节点，因此需要设置虚拟头节点，然后从头节点开始进行逐个判断。
```
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode cur = dummyHead;
        while(cur.next != null){
            if(cur.next.val == val){
                cur.next = cur.next.next;
            }else{
                cur = cur.next; 
            }
                        
        }
        return dummyHead.next;
    }
}
```
