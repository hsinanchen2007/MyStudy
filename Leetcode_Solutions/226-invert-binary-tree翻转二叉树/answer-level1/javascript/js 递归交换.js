![image.png](https://pic.leetcode-cn.com/7ed7904fd070eaeed1e0e92779dcbea84407e038b3cc369297723c14d21f0ff0-image.png)

### 解题思路
```js
  把左子树反转后给右子树，右子树反转后给左子树，要使用一个临时变量
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

var invertTree = function(root) {
  function invert(node) {
    if (node === null) return null;
    
    let temp = node.left;
    node.left = invert( node.right );
    node.right = invert( temp );
    
    return node;
  }
  
  invert( root );
  
  return root;
};
```