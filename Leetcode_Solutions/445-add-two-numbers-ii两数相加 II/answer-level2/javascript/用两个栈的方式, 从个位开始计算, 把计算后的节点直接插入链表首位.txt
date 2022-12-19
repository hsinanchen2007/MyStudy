```
// 445. 两数相加 II
var addTwoNumbers_II = function(l1, l2) {
    //学会用栈的方式解决问题
    let stack1 = [];
    let stack2 = [];

    while(l1) {
        stack1.push(l1);
        l1 = l1.next;
    };

    while(l2) {
        stack2.push(l2);
        l2 = l2.next;
    }

    let dummyHead = { next: null };
    let carry = 0;

    while ( stack1.length  || stack2.length ) {
        let p1 = stack1.pop();
        let p2 = stack2.pop();

        let x = p1 ? p1.val : 0;
        let y = p2 ? p2.val : 0;

        let sum = x + y + carry;
        let b = sum % 10;              //个位
        let a = Math.floor( sum / 10); //十位
        //直接把新来的节点插入首位
        dummyHead.next =  { val: b , next: dummyHead.next };
        carry = a;
    };
    
    if (carry) {
        dummyHead.next =  { val: carry , next: dummyHead.next };
    };
    return dummyHead.next;
};
```

