```js
var mergeTwoLists = function(l1, l2) {
  const dummy = new ListNode();

  let current = dummy;
  let p1 = l1;
  let p2 = l2;

  while (p1 || p2) {
    if ((p1 && p2 && p1.val <= p2.val) || !p2) {
      current.next = p1;
      p1 = p1.next;
    } else {
      current.next = p2;
      p2 = p2.next;
    }

    current = current.next;
  }

  return dummy.next;
};
```

```js
var mergeTwoLists = function(l1, l2) {
  const dummy = new ListNode();

  let p = dummy;

  while (l1 && l2) {
    // 解构法交换变量值太占用空间了, 跑分时慎用
    l1.val > l2.val && ([l1, l2] = [l2, l1]);

    p.next = l1;
    l1 = l1.next;
    p = p.next;
  }

  // 尾部处理, 省去了遍历
  p.next = l1 ? l1 : l2;

  return dummy.next;
};
```