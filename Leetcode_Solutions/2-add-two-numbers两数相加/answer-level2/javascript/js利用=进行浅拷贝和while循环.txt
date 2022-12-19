### 解题思路
利用curr作为中间对象进行浅复制
利用while进行循环

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var carry = 0;
    var head = new ListNode(0);
    var curr = head;

    while(l1 || l2 || carry) {
        var sum = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + carry;
        curr = curr.next = new ListNode(sum % 10);

        l1 = l1 ? l1.next : null;
        l2 = l2 ? l2.next : null;
        carry = Math.floor(sum / 10);
    }

    return head.next;
};
```