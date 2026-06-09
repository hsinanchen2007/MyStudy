1. 双链表拼接，小于目标数的构建前链表，大于或等于构建后链表，前链表末尾节点指向后链表头节点
```js
var partition = function(head, x) {
    var before = new ListNode(-1);
    var beforeNode = before;
    var after = new ListNode(-1);
    var afterNode = after;
    while(head){
        if(head.val < x){
            before.next = head;
            before = before.next;
        }else{
            after.next = head;
            after = after.next;
        }
        head = head.next;
    }
    after.next = null;
    before.next = afterNode.next;
    return beforeNode.next;
};
```
2. 将链表转换成数组进行排序，再将数组转换程链表
```js
var partition = function(head, x) {
    var arr = [], res1 = [], res2 = [], res = [], resHead = null;
    while(head){
        arr.push(head.val);
        head = head.next;
    }
    arr.forEach((val, idx)=>val<x?res1.push(val):res2.push(val));
    res = res1.concat(res2);
    for(var i=res.length-1;i>-1;i--){
        resHead = {val: res[i], next: resHead};
    }
    return resHead;
};
```