### 解题思路
执行用时 :56 ms, 在所有 JavaScript 提交中击败了99.75%的用户
内存消耗 :35.6 MB, 在所有 JavaScript 提交中击败了100.00%的用户

思路就是普通的双指针
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
var deleteNode = function(head, val) {
    let pre = head
    let cur = head.next
    if(pre.val === val) return cur
    while(pre !== null && pre.next !== null) {
    if(cur.val === val) {
        pre.next = cur.next
    }
    pre = pre.next
    cur = cur.next
    }
    return head
};
```