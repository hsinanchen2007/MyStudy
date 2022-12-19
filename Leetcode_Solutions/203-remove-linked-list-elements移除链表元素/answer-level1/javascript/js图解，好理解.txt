![image.png](https://pic.leetcode-cn.com/bc3bab57bdccbad5bf9e818badc73437e6cb8107ecda0cd6bfed989790345f88-image.png)

### 图解
![image.png](https://pic.leetcode-cn.com/79abd00de9bc8811483d019b86b1eafd7f3735800cc244012cde7b8a3d1dd751-image.png)

### 解题思路
链表的基本操作：删除链表节点
1.遍历链表，遇到等于给定值的节点，那么把这个值的上一个节点连接到这个值的下一个节点上，就相当于删除该值
2.需要的指针 prev，curr

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
 * @param {number} val
 * @return {ListNode}
 */

var removeElements = function(head, val) {
  let newHead = new ListNode( null ),
      prev = newHead,
      curr = head;
  newHead.next = head;
  
  while (curr) {
    if (curr.val === val) {
      prev.next = curr.next;
      curr = prev.next;
    }
    else {
      prev = curr;
      curr = curr.next;
    }
  }
  
  return newHead.next;
};
```