```
public ListNode oddEvenList(ListNode head) {
        if(head==null||head.next==null)
            return head;
        //fhead标记第一个节点；head用于标记重新排列好的奇数节点的尾节点
        ListNode fhead=head;   
        //shead标记第二个节点，point用于标记重新排列好的偶数节点的尾节点 
        ListNode shead= head.next,point=shead;     
        while(head.next!=null&&head.next.next!=null){
            head.next=head.next.next;
            head=head.next;
            while (point.next!=null&&point.next.next!=null){
                point.next=point.next.next;
                point=point.next;
                break;
            }
        }
        head.next=null;      //需要切断，不然会出现多个节点循环的情况
        point.next=null;
        head.next=shead;
        return fhead;
    }
```
