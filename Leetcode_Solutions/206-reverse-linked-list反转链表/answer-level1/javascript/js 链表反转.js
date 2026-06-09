### 解题思路
通过迭代反转前一个与后一个结点来达到反转的目的。
注意处理边界值和头尾结点。

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
    if (head ===null || head.next === null) {
        return head;
    }
    let p1 = head;
    let p2 = head.next;
    let p3 = head.next.next;

    while(p2) {
        p3 = p2.next;
        p2.next = p1;
        p1 = p2;
        p2 = p3;
    }
    head.next = null;
    head = p1;

    return head;
};
```