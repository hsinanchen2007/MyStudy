### 解题思路
依次向下读取，每读取2位，中点向后推1位

![image.png](https://pic.leetcode-cn.com/c85398a421494464390c68492debcd2b5b7eb1b82b25c7dbb4624c64b02a732d-image.png)


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
  let mid = head;
  let move = 1;
  let curNode = head;

  while(curNode.next){
    curNode = curNode.next;
    if(move){
      mid = mid.next;
    }
    move = 1 - move;
  }

  return mid;
};
```