![image.png](https://pic.leetcode-cn.com/b30e94c0156118d62dd83573eba2031f200b40b358a365b1cc5613abd85fe963-image.png)

### 解题思路
```js
  中序遍历 + 不断构建右子树
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
 * @return {TreeNode}
 */

var convertBiNode = function(root) {
  let ans = new TreeNode(null), p = ans;
  
  function bst(node) {
    if (node === null) return ;
    bst(node.left);
    p.right = new TreeNode(node.val);
    p.left = null;
    p = p.right;
    bst(node.right);
  }
  
  bst(root);
  
  return ans.right;
};
```