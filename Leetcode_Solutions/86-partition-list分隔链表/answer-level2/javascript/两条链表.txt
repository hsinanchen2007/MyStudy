### 解题思路
用两条链表，一条放值小于 val 的节点，一条放值大于等于 val 的节点
最后合并两条链表

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
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    const dumpy1 = new ListNode(-1), dumpy2 = new ListNode(-1);
    dumpy1.next = head;
    let left = dumpy1, right = dumpy2;
    while (left && left.next) {
        const current = left.next;
        if (current.val >= x) {
            right.next = current;
            right = current;
            left.next = current.next;
            current.next = null;
        } else {
            left = current;
        }
    }
    left.next = dumpy2.next;
    return dumpy1.next;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)