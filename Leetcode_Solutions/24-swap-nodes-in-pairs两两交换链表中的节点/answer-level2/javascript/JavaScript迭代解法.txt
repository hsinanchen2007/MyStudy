JS方面还是需要建立一个空的头结点来保存整个联表的访问，然后就整个引用的转化过程比较繁复了~

```
var swapPairs = function(head) {
    let target = new ListNode(0);
    let pre = target;
    pre.next = head;
    while(pre.next&&pre.next.next){
        let cur = pre.next;
        let next = cur.next;
        let temp = next.next;
        cur.next = temp;
        next.next = cur;
        pre.next = next;
        pre = cur;
    }
    return target.next;
};
```
