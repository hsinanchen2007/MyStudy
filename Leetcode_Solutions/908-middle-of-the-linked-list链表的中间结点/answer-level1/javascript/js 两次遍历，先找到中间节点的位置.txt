![image.png](https://pic.leetcode-cn.com/9ec76cdac0d18f252b0cc56c880021b119560830ac75dbfdd41fe59c9f57f35c-image.png)

### 解题思路
```js
  思路：遍历两次
  1.计算链表长度，找到中间节点的位置
  2.遍历一次链表，找到中间节点返回
```

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
  let len = 0, headcopy = new ListNode( null );
  headcopy.next = head;
  headcopy = headcopy.next;
  while (head !== null) {
    len++;
    head = head.next;
  }
  
  let mid = Math.floor( len / 2 ) + 1;
  
  while (mid > 1) {
    headcopy = headcopy.next;
    mid--;
  }
  
  return headcopy;
};
```