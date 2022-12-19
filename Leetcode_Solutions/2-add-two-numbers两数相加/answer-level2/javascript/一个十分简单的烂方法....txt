基本思路就是：
1.把两个链表的数相加放到一个数组里，如果其中一个链表长度不足的话，就补0
2.处理进位问题
3.转成链表输出


var addTwoNumbers = function(l1, l2) {
    
    let list = [];

    while(l1 !== null || l2 !== null){

        list.push((l1 ? l1.val : 0) + (l2 ? l2.val : 0));

        l1 = l1 ? l1.next : null;
        l2 = l2 ? l2.next : null;

    }

    console.log(list);

    let nodes = [];
    for(let i = 0;i<list.length;i++){
        let node = new ListNode(list[i]);
        nodes.push(node);
    }

    for(let i=0;i<nodes.length;i++){

        nodes[i].next = nodes[i+1] ? nodes[i+1] : null;

        let num = ((nodes[i].val / 10)+'').split('.').map(Number);

        if(num[0] > 0){
            nodes[i].val = num[1] ? num[1] : 0;
            if(nodes[i+1]){
                nodes[i+1].val = nodes[i+1].val + num[0];
            }else{
                nodes[i].next = new ListNode(num[0]);
            }
        }

    }

    return nodes[0];

};