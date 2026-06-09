### 解题思路
1. 和反转链表差不多，但用了三个数组来放置节点，空间占用较多
2. 主要是边界条件的处理比较费劲

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
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function(head, m, n) {
    let chain1 = [], chain2 = [], chain3 = [], pointer = head, index = 0, _head = head, tmpNext, lastNode = null
    while (pointer) {
        index++
        if (index < m) {
            chain1.push(pointer)
            pointer = pointer.next
        } else if (index >= m && index <=n) {
            chain2.unshift(pointer)
            tmpNext = pointer.next
            pointer.next = lastNode
            lastNode = pointer
            pointer = tmpNext
        } else {
            chain3.push(pointer)
            pointer = pointer.next
        }
    }
    let c1l = chain1.length, c2l = chain2.length, c3l = chain3.length
    let c1tail = chain1[c1l - 1],
        c2head = chain2[0],
        c2tail = chain2[c2l -1],
        c3head = chain3[0]
    if (c1tail) {
        c1tail.next = c2head || c3head || null
    }
    if (c2tail) {
        c2tail.next = c3head || null
    }
    if (c1l) {
        _head = chain1[0]
    } else if (c2l) {
        _head = chain2[0]
    } else if (c3l) {
        _head = chain3[0]
    }
    return _head
};
```