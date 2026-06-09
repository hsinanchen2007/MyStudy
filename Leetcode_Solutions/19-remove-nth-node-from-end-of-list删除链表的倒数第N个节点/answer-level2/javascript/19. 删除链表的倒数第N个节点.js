双循环法
通过一次遍历得到链表长度，使用链表长度以及n计算得到目标节点索引值，再次遍历链表删除目标节点
```
var removeNthFromEnd = function(head, n) {
    let dump = new ListNode();
    dump.next = head;
    let linkedLength = 0;
    let num = dump;
    while(num.next != null){
        linkedLength++;
        num = num.next;
    }
    let index = linkedLength-n+1;
    let pre = dump;
    let cur = pre.next;
    for(let i = 1;i<index;i++){
        pre = cur;
        cur = pre.next;
    }
    pre.next = cur.next;
    return dump.next;
};
```
