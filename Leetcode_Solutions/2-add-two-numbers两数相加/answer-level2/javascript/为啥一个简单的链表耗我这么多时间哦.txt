### 解题思路
1. 提交代码中不要包含console 严重影响效率，比其他的优化影响的多。
2. 需要注意的一步：将链表的指针作为一个独立变量存储，好处是链表本身的指向不会改变
3. 活用取余等现有方法

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let lastNode = new ListNode('head');
    let temp = lastNode;
    let lastTick = 0;

    while (l1 || l2 || lastTick) {
        const v1 = l1?Number(l1.val):0;
        const v2 = l2?Number(l2.val):0;
        let value = v1 + v2 + lastTick;
        lastTick = parseInt(value/10)
        value = value % 10

        temp.next = new ListNode(value);

        temp = temp.next

        if(l1) l1 = l1.next
        if(l2) l2 = l2.next

    }
    return lastNode.next
};
```