var swapPairs = function(head) {
     //定义指向待排链表的节点
     let emptyNode = new ListNode();
     emptyNode.next = head;
     //游标节点，用于遍历(这个很重要)
     let flagNode = emptyNode;
     while(flagNode.next && flagNode.next.next){
         //前置节点
         let firstValue = flagNode.next;
         //后置节点
         let lastValue = firstValue.next;
         //待排节点的反转
         flagNode.next = lastValue;
         //将未排数据，链接到反转之后的最后节点()
         firstValue.next = lastValue.next;
         //重置已排首节点的指向
         lastValue.next = firstValue;
         //游标下移
         flagNode = firstValue
     }
     return emptyNode.next;
};