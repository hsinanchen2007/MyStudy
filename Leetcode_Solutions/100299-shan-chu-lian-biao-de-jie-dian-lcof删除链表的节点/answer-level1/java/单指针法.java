创建虚拟头结点，判断P结点的下一个是否是需要删除的值，如果是，则将p指向删除结点的下一个，无需特殊考虑尾结点和头结点
```
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
       //创建虚拟头结点
       ListNode vir_head=new ListNode(0);
       vir_head.next=head;
       ListNode p=vir_head;
       while(p.next!=null){
           if(p.next.val==val){
               p.next=p.next.next;
               break;
           }
           p=p.next;
       }
       return vir_head.next;
    }
}
```
