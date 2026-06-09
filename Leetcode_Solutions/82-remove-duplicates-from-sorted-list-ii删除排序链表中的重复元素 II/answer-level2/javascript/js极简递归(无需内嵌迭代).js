```js
var deleteDuplicates = function(head, preVal = null) {
  if (!head) return head;

  // 连续相同
  if (head.val === preVal || (head.next && head.val === head.next.val)) {
    return deleteDuplicates(head.next, head.val);
  }

  // 不相同
  head.next = deleteDuplicates(head.next, head.val);

  return head;
};
```