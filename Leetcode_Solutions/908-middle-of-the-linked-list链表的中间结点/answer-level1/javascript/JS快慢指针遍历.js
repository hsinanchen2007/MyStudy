### 解题思路
从头遍历链表，慢指针一次走一个结点，快指针一次走两个结点。当快指针到走到尾结点（或者走到了null），停止遍历，慢指针刚好在中间结点（偶数个结点时，有两个中间结点，正好返回第二个中间结点）

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
    // 边界条件判断
    if (head == null || head.next == null) {
        return head;
    }
    
    let middle = head;
    while (head !== null && head.next !== null) {
        middle = middle.next;
        head = head.next.next;
    }
    return middle;
};
```