![image.png](https://pic.leetcode-cn.com/d377978bda810a59c835bf51e31e545e3fbfe7ec547fb8ca4074d68f1d4cec26-image.png)

### 解题思路
```js
遍历树，中序遍历
从每个点进行 dfs，只要找到路径和为 sum，计数一次
注意：如果在某个路径中找到了一种解法，仍然要继续向下搜寻，因为可能后面
      还会有符合条件的路径，举例： `1 + 2 + 3 = 6`，那么继续搜索，再加上两个数
      `1 + 2 + 3 + 5 + -5 = 6`，仍然是一条符合条件的路径
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
 * @return {number}
 */

var pathSum = function(root, sum) {
  let count = 0;
  
  function recursion(node) {
    if (node === null) return ;
    
    recursion( node.left );
    dfs(node.val, node);
    recursion( node.right );
  }
  
  function dfs(curr, node) {
    if (curr === sum) count++;
    if (!node.left && !node.right) return ;
    
    if (node.left) {
      dfs(curr + node.left.val, node.left);
    }
    
    if (node.right) {
      dfs(curr + node.right.val, node.right);
    }
  }
  
  recursion( root );
  
  return count;
};
```