### 解题思路
parseInt方法取值, 也可以把链表转数组

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
 * @return {number}
 */
var getDecimalValue = function(head) {
    let node = head;
    let str = ''
    while(node !== null){
        str += node.val;
        node = node.next;
    }
    return parseInt(str, 2)
};
```