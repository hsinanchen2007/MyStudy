### 解题思路
此处撰写解题思路
快指针先走k，之后快慢指针同时走，直到快指针走到最后一个元素，此时快慢指针相差k
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
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd = function(head, k) {
    let fastNode = head
    let lowNode = head

    while(k--){
        fastNode = fastNode.next
    }
    while(fastNode){
        fastNode = fastNode.next
        lowNode = lowNode.next
    }
    return lowNode
};
```