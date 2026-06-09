![image.png](https://pic.leetcode-cn.com/ffe6056f4ef28ef009a82a2208f3d6122a945d531e11cc30ad457ebbe8e6fb3f-image.png)

### 解题思路
```js
  借用评论区的一句话：中序遍历为升序
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

var isValidBST = function(root) {
  let ans = true, lastVal = -Infinity;
  
  function bst(node) {
    if (ans === false) return ;
    if (node === null) return ;
    
    bst(node.left);
    if (node.val <= lastVal) return ans = false;
    lastVal = node.val;
    bst(node.right);
  }
  
  bst(root);
  
  return ans;
};
```