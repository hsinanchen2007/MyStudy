### 解题思路
此处撰写解题思路

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
var swapPairs = function(head) {
    if (head && head.next) {
        var fistNode = head;
        var secondNode = head.next;

        fistNode.next = swapPairs(secondNode.next);
        secondNode.next = fistNode;

        return secondNode;
    }

    return head;
};
```