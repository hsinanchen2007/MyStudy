### 解题思路
js实现，p指向head，每次使得p.next变为head，p指向下一个节点，依次循环

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
    if (head == null) {
        return null;
    }
    var p = head;
    while ( p.next != null) {
        var q = p.next;
        p.next = p.next.next;
        q.next = head;
        head = q;
    }
    return head;
};
```