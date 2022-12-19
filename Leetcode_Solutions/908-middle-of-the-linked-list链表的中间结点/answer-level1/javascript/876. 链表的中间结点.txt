### 解题思路
双指针

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
    let pre = head
    while(pre && pre.next){
        head = head.next
        pre = pre.next.next
    }
    return head
};
```