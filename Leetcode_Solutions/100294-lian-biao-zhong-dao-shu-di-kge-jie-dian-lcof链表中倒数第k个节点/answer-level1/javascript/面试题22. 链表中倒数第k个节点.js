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
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd = function(head, k) {
    let result = head
    for(let i = 0; i < k - 1; i++){
        head = head.next
    }
    while(head && head.next){
        head = head.next
        result = result.next
    }
    return result
};
```