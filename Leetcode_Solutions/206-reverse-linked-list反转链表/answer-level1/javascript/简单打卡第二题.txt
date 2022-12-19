### 解题思路
1. 判定边界条件
2. 设置next初始值（previous）
3. 循环遍历head
4. 保存当前节点值的next（用于后续遍历）为node
5. 当前节点值的next为previous
6. 保存当前节点值为previous
7. 保存之前的node为head（重新遍历）

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
    if(!head) return null
    var previous = null
    while(head.next){
        const node = head.next
        head.next = previous
        previous = head
        head = node
    }
    head.next= previous
    return head
};
```