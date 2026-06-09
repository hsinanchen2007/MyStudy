### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * function ImmutableListNode() {
 *    @ return {void}
 *    this.printValue = function() { // print the value of this node.
 *       ...
 *    }; 
 *
 *    @return {ImmutableListNode}
 *    this.getNext = function() { // return the next node.
 *       ...
 *    };
 * };
 */

/**
 * @param {ImmutableListNode} head
 * @return {void}
 */
const printLinkedListInReverse = head => { // 递归算法...

    if (!head) return

    printLinkedListInReverse(head.getNext())
    head.printValue()
};

const printLinkedListInReverse2 = head => { // 非递归算法...

    let stack = [], p = head
    while (p) {
        stack.push(p)
        p = p.getNext()
    }

    while (stack.length)
        stack.pop().printValue()
};
```