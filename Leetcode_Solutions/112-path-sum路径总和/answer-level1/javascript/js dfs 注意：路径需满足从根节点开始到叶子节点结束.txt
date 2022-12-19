![image.png](https://pic.leetcode-cn.com/f1166c869684f2c098a9e4c82ef2b3afa8fe8a818dd55a516e7798e1349c46f1-image.png)

### 解题思路
```js
从根节点开始 dfs，一旦找到符合条件的路径，终止递归，返回 true 即可，
否则，最后返回 false
注意：路径需满足从根节点开始到叶子节点结束
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
 * @param {number} sum
 * @return {boolean}
 */

var hasPathSum = function(root, sum) {
  function dfs(curr, node) {
    if (node === null) return ;
    curr += node.val;
    
    if (curr === sum && !node.left && !node.right) {
      return ans = true;
    }
    
    if (node.left) dfs(curr, node.left);
    if (node.right) dfs(curr, node.right);
  }
  
  let ans = false;

  dfs(0, root);

  return ans;
};
```