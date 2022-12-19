var addTwoNumbers  = function(l1 , l2) {
    if(l1 === null) return l2;
    if(l2 === null) return l1;
    let count = 0;
    let curry = new ListNode('head');
    let head = curry;
    let val;
    while(l1 || l2) {
        if(l1 === null)  {
            val = l2.val + count;
        } else  if(l2 === null) {
            val = l1.val + count;
        } else {
            val = l1.val + l2.val + count;
        }
        count = 0;
        if(val >= 10) {
            count = parseInt((val % 100) /10);// 取数字的十位
            val = val % 10;//个位
        }
        curry.next = new ListNode(val);
        curry = curry.next;
        if(l1) {
            l1 = l1.next;
        }
        if(l2) {
            l2 = l2.next;
        }
    }
    if(count !== 0) {
        curry.next = new ListNode(count);
    }
    return head.next;
}