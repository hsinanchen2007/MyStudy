### analyze

```js
prev  first  second  next
        1  ->  2  ->  3  ->  4 -> null
              .
              .
进行如下指针变换:
prev -> second -> first -> next
          2    ->   1   ->  3  ->  4 -> null
              .
              .
移动指针:
                   prev   first  second  next
          2    ->   1   ->  3  ->  4 -> null
              .
              .
重复上述操作
```

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
  const dummyHead = new ListNode(0)
  dummyHead.next = head

  let prev = dummyHead
  let first = prev.next

  while(first && first.next) {
    let second = first.next
    let next = second.next

    second.next = first
    first.next = next
    prev.next = second

    prev = first
    first = first.next
  }

  return dummyHead.next
}
```

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/LeetCode/README.md)