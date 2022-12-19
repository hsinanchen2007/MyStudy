### 解题思路
本次提交才用递归方式反转链表

反转链表只需要把后面一个元素指向前一个元素，且最后一个为head，原head指向null

于是在设计递归函数的时候便只需要实现将传入两个参数，将后一个指向前一个即可
结束条件为循环完整个链表即最后一个元素，我们知道最后一个元素的下一个为空，所以以此判断

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
    let reverseFn = (pre, cur) => {
        if(!cur) return pre
        let next = cur.next
        cur.next = pre
        return reverseFn(cur, next)
    }
    return reverseFn(null, head)
};
```