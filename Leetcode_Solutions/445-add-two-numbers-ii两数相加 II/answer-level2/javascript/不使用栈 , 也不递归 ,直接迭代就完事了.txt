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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
function reverse(root) {
  let currNode = root;
  let pre = null;
  while(currNode !== null) {
    let nextTemp = currNode.next;
    currNode.next = pre;
    pre = currNode;
    currNode = nextTemp;
  }
  return pre;
}
var addTwoNumbers = function(l1, l2) {
    let newL1 = reverse(l1);
    let newL2 = reverse(l2);
    let carry = 0;
    let dummy = new ListNode(0); // 哑节点
    let res = dummy;
    while(newL1 !== null || newL2 !== null) {
      if(newL1 == null) newL1 = new ListNode(0);
      if(newL2 == null) newL2 = new ListNode(0);
      let sum = newL1.val + newL2.val + carry;
      dummy.next = new ListNode(sum % 10);
      carry = Math.floor(sum / 10);
      newL1 = newL1.next;
      newL2 = newL2.next;
      dummy = dummy.next;
    }
    if(carry !== 0) dummy.next = new ListNode(carry);
    return reverse(res.next);
};
```