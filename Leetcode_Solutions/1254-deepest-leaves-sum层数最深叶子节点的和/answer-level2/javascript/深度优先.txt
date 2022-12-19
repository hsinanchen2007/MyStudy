### 解题思路
深度优先

### 代码

```javascript
/**
 * Definition for a binary tree node.
 *
 /**
  * Definition for a binary tree node.
  * function TreeNode(val) {
  *     this.val = val;
  *     this.left = this.right = null;
  * }
  */
 /**
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
  var deepestLeavesSum = function (root) {
      let sum = 0
      let depth = 0

      function helper(root, level) {
          if (!root) return
          if (!root.left && !root.right) {
              if (level > depth) {
                  sum = root.val
                  depth = level
              }
              else if (level === depth) {
                  sum += root.val
              }

          }
          helper(root.left, level + 1)
          helper(root.right,level+1)
      }
      helper(root, 1)
      return sum
  };
```