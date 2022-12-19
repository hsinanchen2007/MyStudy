### 解题思路
遍历链表存成两个数组，再把数组拼接起来成为一个大数组，再遍历一次这个数组形成新链表，时间复杂度为O(n)

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
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    let arr = [], arrBigger = [], pointer = head, idx = 0
    while (pointer) {
        if (pointer.val < x) {
            arr.push(pointer)
        } else {
            arrBigger.push(pointer)
        }
        pointer = pointer.next
    }
    let result = arr.concat(arrBigger)
    result.forEach((node, index) => {
        node.next = result[index+1] || null
    })
    return result[0] || head
}
```