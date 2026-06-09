### 解题思路
1、将各个节点递归遍历存储在栈【数组头部插入模拟】中
2、通过弹栈取出，形成数组值

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
 * @return {number[]}
 */
function inStack(head, stack = []) {
    let nextNode = null
    if(head === {} || !head) {
        return stack
    }
    if(head.next) {
        nextNode = head.next
        head.next = null
        stack.unshift(head)
        return inStack(nextNode, stack)
    }else {
        stack.unshift(head)
        return stack
    }
}
var reversePrint = function(head) {
    return inStack(head).map(item => item.val)
};
```