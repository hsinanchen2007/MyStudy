### 解题思路

迭代

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
    let pre = null;
    let top = head;
    while(top){
        let next = top.next;
        top.next = pre;
        pre = top;
        top = next;
    }
    return pre;
};
```