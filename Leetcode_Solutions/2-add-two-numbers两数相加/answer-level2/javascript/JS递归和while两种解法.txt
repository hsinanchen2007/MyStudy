```
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2, added = 0) {
  let n = new ListNode()
  !l1 && (l1= new ListNode(0));
  !l2 && (l2= new ListNode(0));

  let sum = l1.val + l2.val + added
  if (sum < 10) {
    added = 0
    n.val = sum
  } else {
    n.val = sum - 10
    added = 1
  }

  if (l1.next || l2.next || added) {
    n.next = addTwoNumbers(l1.next ,l2.next,  added)
  }
  return n
};
```

思路就是加一个标志位来标示上一个相加的是不是有进1
用while写的话不需要在function上加added这个额外的参数，而且在 输入为[1] [1,2,3,4,5,6,8,6,7,8] 这种两个链表相差很大的情况下因为事先声明好了一个e (值为0的节点)，所以会减少创建listNode的次数
```
// while
var addTwoNumbers = function(l1, l2) {
  let start = n = new ListNode()
  let e = new ListNode(0)
  let added = 0
  while(l1 || l2) {
    l1 = l1 || e
    l2 = l2 || e
    let sum = l1.val + l2.val + added
    added = Math.floor(sum / 10)
    n.next = new ListNode(sum % 10)
    n = n.next
    l1 = l1.next
    l2 = l2.next
  }
  if (added) {
    n.next = new ListNode(added)
  }
  return start.next
};
```




