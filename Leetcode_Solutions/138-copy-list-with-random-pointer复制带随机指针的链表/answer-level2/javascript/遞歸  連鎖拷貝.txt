### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function(head) {
  if (head == null) return null;
  if (head.copy) return head.copy;
  const copy = new Node(head.val);
  head.copy = copy;
  if (head.next) copy.next = copyRandomList(head.next);
  if (head.random) copy.random = copyRandomList(head.random);
  return copy;
};
```