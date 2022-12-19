### 解题思路
此处撰写解题思路

 - 利用js 对象的引用
 - 确保进位
 - 确保最后一个节点的node.next为null
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
    const res = { val: 0 };
    let now = res;
    let last = 0;
    let a = l1;
    let b = l2
    while(now) {
        // 因为Number(undefined) = null ,所以有a.val || 0，来确保和不为NaN
        const res = (a.val || 0) + (b.val || 0) + last;
        now.val = res % 10;
        last = Math.floor(res/10);
        a = a.next || {};
        b = b.next || {};
        // 确保last有值时去进位，并确保都无值时，最后一个last.next === null
        if(a.val !== undefined || b.val !== undefined || last) {
           now.next = {}
        }
        // 指向下一个节点；
        now = now.next;      
    } 
    return res;
};
```