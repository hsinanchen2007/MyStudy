### 解题思路
用一个数组存储每个节点，循环得到链表长度，取数组对应索引

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
var middleNode = function(head) {
    const temp = []
    let len = 0
    let current = head
    while (current) {
        len ++
        temp.push(current)
        current = current.next
    }
    return len % 2 ? temp[Math.floor(len / 2)] : temp[len / 2]
};
```