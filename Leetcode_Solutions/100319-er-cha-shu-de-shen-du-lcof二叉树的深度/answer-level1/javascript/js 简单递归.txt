![image.png](https://pic.leetcode-cn.com/fa526dd3e0bcd8c069c1d9363e1a3a7e43922534889e249dda558eb36622a7ac-image.png)

### 解题思路
```js
简单递归，不断获取左右两个节点较大的那个分支的深度，递归计算
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

var maxDepth = function(root) {
  if (root === null) return 0;
  
  let left = maxDepth( root.left ),
      right = maxDepth( root.right );
  
  return Math.max(left, right) + 1;
};
```