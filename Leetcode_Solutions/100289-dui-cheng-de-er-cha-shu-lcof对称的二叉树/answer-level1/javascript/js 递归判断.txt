![image.png](https://pic.leetcode-cn.com/98c259b88ea9f61732ebd175cdc1cd8f7a608a41bded54c127593436929a7242-image.png)

### 解题思路
```js
两个子节点相等，并且A的左节点等于B的右节点的值
B的左节点等于A的右节点的值
```

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
 * @return {boolean}
 */

var isSymmetric = function(root) {
  if (root === null) return true;
  
  function check(left, right) {
    if (left === null && right === null) return true;
    if (left === null || right === null) return false;
    if (left.val !== right.val) return false;
    return check(left.left, right.right) && check(left.right, right.left);
  }
  
  return check(root.left, root.right);
};
```