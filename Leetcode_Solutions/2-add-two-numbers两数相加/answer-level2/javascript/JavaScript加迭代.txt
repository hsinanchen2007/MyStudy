var addTwoNumbers = function(l1, l2) {
    result = new ListNode(0);
    genNext(l1,l2,result);
    return result;
};

function genNext(o1,o2,curNode) {
    let val = o1.val + o2.val + curNode.val;
    let adv = Math.floor(val/10);
    curNode.val = val%10;
    
    if(o1.next||o2.next||adv>0){
        curNode.next = new ListNode(adv);
        curNode = curNode.next;
        o1 = (o1.next != null) ? o1.next : new ListNode(0);
        o2 = (o2.next != null) ? o2.next : new ListNode(0);
    }else{
        //如果没有链表1和俩表2下一个值和进位，则跳出迭代
        return;
    }
        
    return genNext(o1,o2,curNode);
}