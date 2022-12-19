### 解题思路
node指针遍历所有节点，mid表示当前的中间节点。

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
    // 双指针
    let mid = head;
    let node = head;
    let i = 1;
    while(node) {
        if(i % 2 === 0) {
            mid = mid.next;
        }
        i ++;
        node = node.next;
    }
    return mid;
};
```