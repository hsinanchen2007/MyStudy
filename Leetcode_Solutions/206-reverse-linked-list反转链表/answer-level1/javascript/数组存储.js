### 解题思路
遍历一遍链表，依次存入数组，倒序装入链表。

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
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if (!head || !head.next) return head;
    const temp = new Array();
    let current = head;
    while (current) {
        temp.push(current.val);
        current = current.next;
    }
    const dumpy = new ListNode(-1);
    let prev = dumpy;
    for (let i = temp.length - 1; i >= 0; --i) {
        prev.next = new ListNode(temp[i]);
        prev = prev.next;
    }
    return dumpy.next;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)