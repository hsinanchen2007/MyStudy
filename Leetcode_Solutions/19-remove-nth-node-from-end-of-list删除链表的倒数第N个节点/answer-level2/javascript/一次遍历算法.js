**分析：**

我们需要遍历链表，并找到链表中倒数第 `n` 个节点，然后删除它。单向链表的特点是，只能往前遍历无法往后查找。所以，如果要删除某个节点，那必须找到它的前一个节点。

> 当然要删除的节点是 `head` 除外，只需把 `head` 指向 `head.next` 即可删除 `head` 节点。

那么问题转化为：找到倒数第 `n` 个节点的前一个节点 `beforeLastN`，令 `beforeLastN.next = beforeLastN.next.next` 即可删除倒数第 `n` 个节点。

假定链表长度为 `L`，倒数第 `n` 个节点即是第 `L - n + 1` 个节点，那么它的前一个节点便是第 `L - n` 个节点。只要计算出链表的长度 `L` 便很容易解决。

通过**两次遍历**的方法，第一次遍历计算链表的长度 `L`，第二次遍历找到第 `L - n` 个节点，删除随后的节点即可。



下面使用**一次遍历**的算法解决这个问题，定义双指针：

- **`beforeLastN`**: 倒数第 `n` 个节点的前一个节点（当倒数第 `n` 个节点不为 `head` 时）；
- **`cur`**: 当前遍历指向的节点。

**算法：**

1. 首先，让 `cur` 指向链表的第 `n + 1` 个节点，如果 `cur` 为 `null`，那么 `head` 即为要删除的节点。
2. 让 `beforeLastN` 指向 `head`。假定 `cur` 为链表的尾节点，那么 `beforeLastN` 后的第一个节点为目标删除节点。
3. 接下来只需同时向后移动 `beforeLastN` 和 `cur` 直到 `cur` 真正指向链表尾节点即可。

```js
const removeNthFromEnd = function(head, n) {
  // 将 cur 指向 head 的第 n + 1 个节点
  let cur = head;
  while (n--) {
    cur = cur.next;
  }
    
  // 如果倒数第 n 个节点为 head
  if (cur === null) {
    head = head.next;
    return head;
  }
    
  // beforeLastN 和 cur 同时向后移动
  let beforeLastN = head;
  while (cur.next !== null) {
    cur = cur.next;
    beforeLastN = beforeLastN.next;
  }
    
  // 删除倒数第 n 个节点
  beforeLastN.next = beforeLastN.next.next;
    
  return head;
};
```

 [源码](./solution_1.js)

更多 JS 解题：[LeetCode-AC-by-JavaScript](https://github.com/zaviertang/leetcode-ac-by-javascript)