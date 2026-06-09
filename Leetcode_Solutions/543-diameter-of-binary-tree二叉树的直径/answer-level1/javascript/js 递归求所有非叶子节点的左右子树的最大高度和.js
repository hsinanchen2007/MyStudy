![image.png](https://pic.leetcode-cn.com/c46b6d4afd4dc30e8e24fc9163b8502af18756936aa1e9d316b930a1eb30ff53-image.png)

### 解题思路
```js
计算二叉树某个非叶子节点的左右子树的最大高度和
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
 * @return {number}
 */

var diameterOfBinaryTree = function(root) {
  function helper(node) {
    if (node === null) return 0;
    
    let left = helper(node.left),
        right = helper(node.right);
    
    height = Math.max(left + right, height);
    return Math.max(left, right) + 1;
  }
  
  let height = 0;
  helper(root);
  
  return height;
};
```