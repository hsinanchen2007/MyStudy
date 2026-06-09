### 解题思路
单词循环内指针跳两次
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
var middleNode = function (head) {
    let middle = head
    let pointer = head
    while (true) {
        if (pointer.next) {
            if (pointer.next.next) {
                pointer = pointer.next.next
                middle = middle.next
            }
            else return middle.next
        }
        else return middle
    }
};
```