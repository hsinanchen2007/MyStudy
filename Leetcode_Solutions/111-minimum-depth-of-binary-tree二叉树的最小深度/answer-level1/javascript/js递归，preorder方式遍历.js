```
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
var minDepth = function(root) {
  if (!root) {
      return 0;
  }
  function helper(node, level) {
      // 当前层次+1
      const clevel = level + 1;
      // 左右节点都没有，则返回当前层级
      if (!node.left && !node.right) {
          return clevel;
      }
      // 有左子树，没有右子树，返回左子树深度
      if (node.left && !node.right) {
          return helper(node.left, clevel);
      }
      // 有右子树，没有左子树，返回右子树深度
      if (node.right && !node.left) {
          return helper(node.right, clevel);
      }
      // 左右子树都有，则取左、右子树层深的最小值
      return Math.min(helper(node.left, clevel), helper(node.right, clevel));
  }
  return helper(root, 0);
};
```
![image.png](https://pic.leetcode-cn.com/578b8282bf36bd71173f26140d43d9437e61505ee4eba8837a57abf119863737-image.png)
