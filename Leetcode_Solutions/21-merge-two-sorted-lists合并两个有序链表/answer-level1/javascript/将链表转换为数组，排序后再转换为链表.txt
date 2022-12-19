### 解题思路
如题。

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
var mergeTwoLists = function(l1, l2) {
    if(l1 === null && l2 === null) return null;
    const temp = [];
    //将链表转换为数组
    while(l1 !== null) {
        temp.push(l1.val);
        l1 = l1.next;
    }
    while(l2 !== null) {
        temp.push(l2.val);
        l2 = l2.next;
    }
    temp.sort((a,b) => a - b);
    const head = new ListNode(temp[0]);
    let res = head;
    for(let i = 1;i < temp.length;i ++) {
        res.next = new ListNode(temp[i]);
        res = res.next;
    }
    return head;
};
```