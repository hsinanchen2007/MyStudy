### 解题思路
首次一定会计算一次, 用do while

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
 * @return {number}
 */
var getDecimalValue = function(head) {
    let result = 0
    do{
        result = result * 2 + head.val
        head = head.next
    }while(head)
    return result
};
```