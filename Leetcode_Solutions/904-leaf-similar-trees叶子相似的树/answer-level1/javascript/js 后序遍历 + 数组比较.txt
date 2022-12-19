![image.png](https://pic.leetcode-cn.com/9c5653db2a1bff2cc70591bcbe2efd6a3ca0726e613b7a7f1ff2353640175f61-image.png)

### 解题思路
```js
  1. 分别后序遍历出 root1 和 root2 的所有的叶子节点
  2. 比较两个数组是否相等
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
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */

var leafSimilar = function(root1, root2) {
  let arr1 = [], arr2 = [], ans = true;
  
  function bst(node, arr) {
    if (node === null) return ;
    bst(node.left, arr);
    bst(node.right, arr);
    if (node.left === null && node.right === null) {
      arr.push( node.val );
    }
  }
  
  bst(root1, arr1);
  bst(root2, arr2);
  
  if (arr1.length !== arr2.length) return false;
  
  for (let i = 0; i < arr1.length; i++) {
    if (arr1[i] !== arr2[i]) {
      ans = false;
      break;
    }
  }
  
  return ans;
};
```