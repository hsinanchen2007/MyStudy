```js
var reversePrint = function(head) {
  let ArrayList = [];
  while (head) {
    ArrayList.push(head.val);
    head = head.next;
  }
  return ArrayList.reverse();  
};
```