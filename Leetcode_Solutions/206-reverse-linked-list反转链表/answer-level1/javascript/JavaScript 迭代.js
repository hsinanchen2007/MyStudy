### 解题思路
这题我用的是迭代的思路做的。创建一个空的指针prev。当head不为空的时候，先存住head.next，然后head.next指向pre，最后pre，head，next三个指针整体往后移动一位。

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
    // corner case
    if (head === null || head.next === null) {
        return head;
    }

    // normal case
    let prev = null;
    while (head !== null) {
        let next = head.next;
        head.next = prev;
        prev = head;
        head = next;
    }
    return prev;
};
```