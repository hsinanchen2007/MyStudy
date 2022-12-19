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
 * @return {number[][]}
 */
var levelOrder = function (root, res = [], level = 0) {
  if (root === null) {
    return [];
  }

  const curLevelArray = res[level] || (res[level] = []);
  curLevelArray.push(root.val);

  levelOrder(root.left, res, level + 1);
  levelOrder(root.right, res, level + 1);

  return res;

};
```