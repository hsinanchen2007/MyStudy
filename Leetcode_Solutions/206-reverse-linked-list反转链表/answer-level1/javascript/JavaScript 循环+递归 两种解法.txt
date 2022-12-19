### 解题思路

一种是循环，另一种是递归。

都用到了两个额外的指针，一个临时空间。

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
  let [prev, cur] = [null, head];
  if (!head ||!head.next) return head;
  while(cur) {
    let temp = cur.next;
    cur.next = prev;
    prev = cur;
    cur = temp;
  }
  return prev;
};

```



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
  let reverse = function(prev, curr) {
    if ( !curr ) return prev;
    let temp = curr.next;
    curr.next = prev;
    prev = curr;
    curr = temp;
    return reverse(prev, curr)
    
  }
  return reverse(null, head);
};
```
