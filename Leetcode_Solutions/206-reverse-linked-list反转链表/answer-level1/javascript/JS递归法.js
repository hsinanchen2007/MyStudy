### 解题思路
通过画图从最后往前推导来理解递归,递归返回的节点都是当前节点的下一个节点,最终返回的就是最后一个不为零的节点,然后再从递归的栈中取出每一个放入的节点,对每个节点进行处理,指针方向变成逆向,并且当前节点的next为null,到下一个节点时会将当前节点的next变成指向下一个节点.

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
// 递归法
// 可以通过画图从最后往前推导来理解递归
var reverseList = function(head) {
    if(!head || !head.next) return head;
    let nextP = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return nextP;
};
```