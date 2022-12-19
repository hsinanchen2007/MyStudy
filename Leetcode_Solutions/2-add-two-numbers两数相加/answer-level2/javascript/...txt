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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let l3 = 0,
    p1 = l1, 
    p2 = l2
    let node = new ListNode();
    let temp = node
    while(p1 || p2 || l3) {
        let n1 = (p1 && p1.val) ? p1.val : 0;
        let n2 = (p2 && p2.val) ? p2.val : 0;
        let sum = n1 + n2 + l3;
        temp.next = new ListNode(sum%10);
        l3 = parseInt(sum/10);
        temp = temp.next
        p1 = p1 ? p1.next : null;
        p2 = p2 ? p2.next : null;
    }
    return node.next;
};
```