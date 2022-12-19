思路很简单，直接判断当前值和前一个值是否都在G中，当前值在，前一个值不在则count++。
题解：
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
 * @param {number[]} G
 * @return {number}
 */
var numComponents = function(head, G) {
  let cur = head;
  let pre = false;
  let count = 0;
  while (cur) {
    if (G.includes(cur.val)) {  // 这里可以用hash map做时间优化，js 用includes隐藏了一个for循环，这题没有卡时间，无所谓了。
      if (!pre) {
        count++;
        pre = true;
      }
    } else {
      pre = false;
    }
    cur = cur.next;
  }
  return count;
};
// const buildListNode = require('./util/buildListNode');
// console.log(numComponents(buildListNode([0, 1, 2, 3, 4]), [0, 3, 1, 4]));
```

福利：数组转链表

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
function ListNode(val) {
  this.val = val;
  this.next = null;
}
module.exports = function buildBinaryTree(array) {
  let head = new ListNode(array[0]);
  let cur = head;
  array.slice(1).forEach(element => {
    cur.next = new ListNode(element);
    cur = cur.next;
  });
  return head;
};

```

