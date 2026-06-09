### 解题思路
思路还是利用两个指针，第一个指针指向头结点，第二个指针指向第n个结点，当第二个结点到达尾部时，将第一个结点的next指向.next.next。
需要注意的是要处理好空，和n为尾结点的边界情况。

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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    if (!head) {
        return null;
    }
    
    var node1 = head;
    var node2 = head;
    for (var i = 0 ; i < n; i++) {
        node2 = node2.next;
    }
    if (!node2) {
        head = head.next;
        return head;
    }
    while (node2.next != null) {
        node1 = node1.next;
        node2 = node2.next;
    }
    node1.next = node1.next.next;
    return head;
};
```