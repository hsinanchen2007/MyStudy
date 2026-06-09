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
    const arr = [];
    while(head){
        arr.push(head);
        head = head.next;
    }
    return arr[Math.floor(arr.length/2)];
};
```