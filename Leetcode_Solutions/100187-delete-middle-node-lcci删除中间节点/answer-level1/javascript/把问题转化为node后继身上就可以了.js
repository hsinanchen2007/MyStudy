### 解题思路
因为只能访问node, 不能从表头开始遍历, 不能直接把node的前驱指针指向node.next,
因此就想到把node.next.val的值拷贝到node.val, 再把node.next删除,
相当于变相把node节点删除了

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
    // node不是链表头元素, 而是要删除的链表链表中元素node
    // 把node.next.val的值拷贝到node.val
    // 再把node.next删除, 变相等于把node节点删除了
    if (!node.next) {
        return;
    }

    var tmpNext = node.next;
    node.val = tmpNext.val;
    node.next = tmpNext.next;
    tmpNext.next = null;
};
