```javascript
var addTwoNumbers = function(l1, l2) {
  let firstListNode;
  let preListNode;
  // 进位标识符
  let curry = 0;
  while (l1 || l2 || curry === 1) {
    let value1 = l1 ? l1.val : 0;
    let value2 = l2 ? l2.val : 0;
    let tempSum =  value1 + value2 + curry;
    curry = 0;
    if (tempSum > 9) {
      curry = 1;
      tempSum = tempSum % 10;
    }
    const currentListNode = new ListNode(tempSum);
    if (preListNode){
      preListNode.next = currentListNode;
    } else {
      firstListNode = currentListNode;
    }
    // 进行下一轮
    l1 = l1 ? l1.next : null;
    l2 = l2 ? l2.next : null;
    preListNode = currentListNode;
  }
  return firstListNode;
};
```
