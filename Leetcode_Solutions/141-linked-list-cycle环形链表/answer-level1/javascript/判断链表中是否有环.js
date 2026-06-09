### 解题思路
1. 遍历一遍链表，并且使用一个数组存储节点，循环中和数组中的值进行对比来判断链表中是否有环

### 代码
```
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    if (!head) {
        return false
  }
  let linkArr = []
  let p = head
  while(p) {
    let index = linkArr.findIndex(item => item === p)
    if (index !== -1) {
      return true
    }
    linkArr.push(p)
    p = p.next
  }
  return false
};
```
