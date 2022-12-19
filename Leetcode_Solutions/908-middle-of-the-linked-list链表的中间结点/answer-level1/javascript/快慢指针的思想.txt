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
 * @param {ListNode} head
 * @return {ListNode}
 */
var middleNode = function(head) {
    let low = head;
    let fast = head;
    while(fast && fast.next){
        low = low.next;
        fast = fast.next.next;
    }
    return low;
};
```