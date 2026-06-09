### 解题思路
定义一个慢节点一个快节点，慢节点每次前进一步，快节点每次前进两步。迭代结束后，如果链表长度是基数，慢节点则停在中间节点；如果是偶数，慢节点则停在第二个中间节点。

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
var middleNode = function(head) {
    let slow = head, fast = head;
    while (slow.next && fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
};
```