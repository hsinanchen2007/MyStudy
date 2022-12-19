### 解题思路
此处撰写解题思路

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
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    var dummyNode = new ListNode(-1); // 设置一个虚拟头节点
    dummyNode.next = head; 
    var prev = dummyNode; // prev记录当前节点的前一个节点
    while(prev.next) { // 从head开始遍历链表
        if(prev.next.val === val) { // 如果当前节点的值等于val
            prev.next = prev.next.next // 跳过当前的节点
        } else {
            prev = prev.next // 如果不等于，继续遍历链表
        }
    }
    return dummyNode.next; // 返回头节点
};
```