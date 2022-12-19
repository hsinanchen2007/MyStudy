![image.png](https://pic.leetcode-cn.com/43dc0106793ecc0a8e8689716b4a845892844ea24f6c0f97a8bab97b80c38089-image.png)

### 解题思路
```js
递归判断所有的点是否相同，如果树的根节点为 null，那么也是单值二叉树
注意：
  1. 0 是有效的节点值
  2. 设定初始值为 null，他只可以变化一次
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

var isUnivalTree = function(root) {
  function isUnivalTree(node) {
    if (ans === true) {
      if (node === null) return ;
      
      if (node.val !== null && onlyVal === null) {
        onlyVal = node.val;
      }
      if (node.val !== null && node.val !== onlyVal) {
        return ans = false;
      }      
      isUnivalTree(node.left);
      isUnivalTree(node.right);
    }
  }
  
  let ans = true, onlyVal = null;
  isUnivalTree(root);
  
  return ans;
};
```