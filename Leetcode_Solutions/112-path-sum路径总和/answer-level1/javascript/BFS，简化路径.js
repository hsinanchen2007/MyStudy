不用存储叠加的value集合，直接将和叠加到子树即可。

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
 * @param {number} sum
 * @return {boolean}
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
  if (!root) return false;
  let queue = [ root ];
  while(queue.length) {
    const temp = [];
    for (const treeNode of queue) {
      // 若是末尾节点则直接判断是否满足sum条件
      if (!treeNode.left && !treeNode.right && treeNode.val === sum) return true; 
      // 叠加左右节点的值
      if (treeNode.left) {
        treeNode.left.val += treeNode.val
        temp.push(treeNode.left);
      }
      if (treeNode.right) {
        treeNode.right.val += treeNode.val
        temp.push(treeNode.right);
      }
    }
    queue = temp;
  }
  return false;
};
```