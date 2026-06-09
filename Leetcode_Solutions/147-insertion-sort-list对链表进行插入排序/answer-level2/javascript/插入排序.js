### Analyze

head0: 当前已排序列表的最后一个;
pre: 用于遍历当前已排序列表;

```js
       head0
dummy -> 4 -> 2 -> 1 -> 3
            .
            .
pre    head0
dummy -> 4 -> 2 -> 1 -> 3
            .
            .
pre         head0
dummy -> 2 -> 4 -> 1 -> 3
            .
            .
             pre head0
dummy -> 1 -> 2 -> 4 -> 3
            .
            .
                      head0
dummy -> 1 -> 2 -> 3 -> 4
```

```js
        head0
dummy -> -1 -> 5 -> 3 -> 4 -> 0
              .
              .
         pre head0
dummy -> -1 -> 5 -> 3 -> 4 -> 0
              .
              .
              pre head0
dummy -> -1 -> 3 -> 5 -> 4 -> 0
              .
              .
              pre head0
dummy -> -1 -> 3 -> 5 -> 4 -> 0
              .
              .
         pre           head0
dummy -> -1 -> 3 -> 4 -> 5 -> 0
              .
              .
                            head0
dummy -> -1 -> 0 -> 3 -> 4 -> 5
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
var insertionSortList = function(head) {
  const dummy = new ListNode(0)
  dummy.next = head
  let head0 = dummy.next

  while (head0 && head0.next) {
    if (head0.next.val >= head0.val) {
      head0 = head0.next
      continue
    }

    let pre = dummy
    while (pre.next.val < head0.next.val) { pre = pre.next }

    let next = head0.next
    head0.next = next.next
    next.next = pre.next
    pre.next = next
  }

  return dummy.next
}
```

![](https://pic.leetcode-cn.com/e064f9f386b9fa525c940042f77bb66f2e5dbe650532cfbb487cd6d0559323cf.jpg)

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/LeetCode/README.md)
