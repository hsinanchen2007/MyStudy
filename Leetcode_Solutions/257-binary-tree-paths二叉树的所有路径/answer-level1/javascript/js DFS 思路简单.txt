![image.png](https://pic.leetcode-cn.com/21e95dbfeec1f22fd64905068572c0900aa0d7c55caa9c9b255932d7757401d8-image.png)

### 解题思路
```js
DFS
注意的点：
当前路径为空的时候，不需要加 '->' 这个连接符的串
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
 * @return {string[]}
 */

var binaryTreePaths = function(root) {
  function dfs(curr, node) {
    if (!node.left && !node.right) {
      return ans.push( curr );
    }
    
    let connect = curr === '' ? '' : '->';
    if (node.left) {
      dfs(curr + connect + node.left.val, node.left);
    }
    if (node.right) {
      dfs(curr + connect + node.right.val, node.right);
    }
  };
  
  let ans = [];
  
  if (root) dfs('' + root.val, root);
  
  return ans;
};


```