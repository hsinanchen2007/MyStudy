### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
  if(root == null) return 0;
  const queue = [];
  let deep = 0;
  queue.push(root);
  while(queue.length !== 0) {
    deep++;
    let len = queue.length;
    while(len !== 0) {
      let node = queue.shift();
      if(node.left) {
        queue.push(node.left);
      }
      if(node.right) {
        queue.push(node.right);
      }
      len--;
    }
  }
  return deep;
};
```