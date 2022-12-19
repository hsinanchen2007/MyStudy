### 解题思路

做这个题，首先需要知道链表是什么，怎么操作链表。然后就是能明白题目的意图，那就很简单了。本题目给的是一个单向链表，需要我们们在只能访问一个 节点的情况下，删除该节点。并且这个节点不是链表的第一个和做后一个节点，是链表除去首尾后的某个节点。

正常情况下，我们想要删除链表的某个节点，操作其实很简单，修改前一个元素的 `next` 就可以了：

```javascript
list.next = list.next.next;
```

![](https://pic.leetcode-cn.com/bf1618c20f65eb33db06b90681d7dc3b5dd44b6617d5d2f9a84031d0749135e8-Screen%20Shot%202020-03-07%20at%205.30.58%20PM.png)

我们让 `list.next` 从 1 跳到值 2。现在值 1 就被从链表中移除了。如果它没有被存储在其它任何地方，那么它会被自动从内存中删除。

但是本题中我们只能访问要删除的节点，所以这个方法用不了。那我们可以把当前节点的下一个节点的值拿过来覆盖掉要删除的值，然后把当前节点的 `next` 指向下一个节点的 `next` 即可。


### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */
var deleteNode = function(node) {
    node.val = node.next.val;
    node.next = node.next.next;
};
```

**复杂度分析：**

- 时间复杂度：O(1)
- 空间复杂度：O(1)

---

**更多题解请关注**：[https://github.com/leviding/leetcode-js-leviding](https://github.com/leviding/leetcode-js-leviding)
