这里建议跟着代码的思路走几个案例就能明白了
1.这里主要是三个指针，一个temp,一个pre,一个head，head指向当前节点，pre指向前一个，temp永远的跟在pre后面，这样就能确保当pre.val=head.val时，直接删除pre和head
2.比大小我是用一个变量VAL和当前节点比大小（第一次认为规定不相等因为第一次比的是我创造的头节点和原链表的第一个节点比），不相等的话，就记录当前节点的值。
public ListNode deleteDuplication(ListNode head) {
        //如果为空链表或者只有一个节点直接返回原头节点
        if (head == null || head.next == null) {
            return head;
        }
        //定义一个哑节点且确保前一个节点的值不等于第一个节点的值
        ListNode dumNode = new ListNode(0);
        dumNode.next=head;
        //用一个值保存
        int val = head.val - 1;
        //指向当前节点的前一个节点的指针
        ListNode pre = dumNode; 
        //用于删除pre指向节点的指针
        ListNode temp = null;
        while (head != null) {
            //第一次是头节点和第一节点比一定是不等的（因为头节点是我创造的）
            if (val == head.val){
                //直接删除pre和head
                temp.next=head.next;
                //把pre指针往后退到处
                pre=temp;
                head=pre.next;
            }else{
                //记录当前节点的值
                val=head.val;
                //确保temp在pre的前面
                temp=pre;
                pre=pre.next;
                head=head.next;
            }
        }
        return dumNode.next;
    }
}