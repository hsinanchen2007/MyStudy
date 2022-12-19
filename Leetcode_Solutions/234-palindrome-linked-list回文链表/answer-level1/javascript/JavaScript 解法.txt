### 解题思路


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
    const temp = []
    let cur = head
    while (cur) {
        temp.push(cur.val)
        cur = cur.next
    }
    for (let i = 0; i < temp.length; i++) {
        if (temp[i] !== temp[temp.length - 1 - i]) {
        return false
        }
    }
    return true
};
```