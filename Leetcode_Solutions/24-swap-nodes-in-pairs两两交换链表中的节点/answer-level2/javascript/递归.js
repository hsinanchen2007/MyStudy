### 解题思路
递归，两两交换节点，让第二个节点指向递归函数，因为递归函数结束后，被交换的值放在前边
最后返回首节点，首节点就是head.next

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
    if(head == null || head.next ==null) {return head}
    let neneNode = head.next.next;
    let nextNode = head.next;
    nextNode.next = head;
    head.next = swapPairs(neneNode)
    return nextNode
};
```