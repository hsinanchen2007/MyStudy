### 解题思路

数组法

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
    if (!head) return null
    const arr = []
    while (head) {
        arr.push(head.val)
        head = head.next
    }
    arr.reverse()
    let res = new ListNode(arr[0])
    let temp = res
    for (let i = 1;  i < arr.length; i++) {
        temp.next = new ListNode(arr[i])
        temp = temp.next
    }
    return res
};
```