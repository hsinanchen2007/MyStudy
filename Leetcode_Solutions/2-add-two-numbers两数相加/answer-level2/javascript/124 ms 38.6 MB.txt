### 解题思路
遍历l1和l2，求每个节点的和，创建l3保存每对节点的和，如果和大于10下一个节点直接创建一个基础值为1的节点，否则创建一个基础值为0的节点。

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
let addTwoNumbers = function(l1, l2) {
   let l3 = new ListNode(null);
    let node = l3;
    while(l1|| l2){
        if(l1) l3.val = l1.val + l3.val;
        if(l2) l3.val = l2.val + l3.val;
        if (l3.val >= 10){
            l3.val = l3.val %10;
            l3.next = new ListNode(1);
            l3 = l3.next;
        }else {
            if((l1&& l1.next) || (l2&& l2.next)){
                l3.next = new ListNode(null);
                l3 = l3.next;
            }
        }
        if (l1) l1 = l1.next;
        if (l2) l2 = l2.next;
    }
    return node;
};
```