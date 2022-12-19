### 解题思路

数组大法

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
 * @return {boolean}
 */
var isPalindrome = function(head) {
    if (!head) return true
    const arr = []
    while (head) {
        arr.push(head.val)
        head = head.next
    }
    const reverse = [...arr].reverse()
    return arr.join('') === reverse.join('')
};
```