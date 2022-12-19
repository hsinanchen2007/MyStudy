### 解题思路
利用递归的思想，自己老是会限于自我递归的深渊，然而脑袋没有机器那么强大，丢不下几个栈就崩皮了

1.首先两两进行递归，将第一个元素设为firstNode，第二个元素设为secondNode
2.firstNode的next应该是指向已经递归的后面两个元素的头元素，这里就是递归的点  ------> firstNode.next = swapPairs(secondNode.next)
3.上面之所以是secondNode.next的是因为它将是后面两两元素的第一个点，套用递归后，它也魔法般的返回了旋转后的元素
4.此时将第二个元素的指向改为第一个元素，完成旋转
5.别忘了结束条件是当只有一个元素时，返回的是它自己

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
    if(!head||!head.next) return head;
    let firstNode = head;
    let secondNode = head.next;
    firstNode.next = swapPairs(secondNode.next)
    secondNode.next = firstNode;
    return secondNode;
};
```