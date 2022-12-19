先加一个哑结点作为头，然后每次取四个节点作为基本单元，如果这四个节点都可以取到，那就可以做交换了，因为都有引用，所以交换很简单。
如果在取中间两个节点的时候发现有null，说明剩下的节点不足两个，或者只有一个null了。这个时候直接返回哑结点的next就可以了。

```js
var swapPairs = function(head) {
    let dummy = new ListNode(0);
    dummy.next = head;
    let cur = dummy;
    while(cur !== null) {
        let first = cur, second = first.next;
        if(second === null) break;
        let third = second.next;
        if(third === null) break;
        let forth = third.next;
        
        first.next = third;
        third.next = second;
        second.next = forth;
        cur = second;
    }
    return dummy.next;
};
```