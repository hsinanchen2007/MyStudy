js 快慢指针
```js
var middleNode = function(head) {
    if(!head) return null;
    let slow = head;
    let quick = head.next;
    while(quick && quick.next) {
        slow = slow.next;
        quick = quick.next.next;
    }
    return quick ? slow.next : slow;
};
```
