```js
var reverseList = function(head) {
    if (!head || !head.next) return head;
    
    let newhead = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    
    return newhead;
};
```