![image.png](https://pic.leetcode-cn.com/896e69ff50a7dea0c801b241c4f59e4e0ab67d6c29d25f6e2f62d6a2e4263e66-image.png)

### 解题思路
```js
递归求每个节点的坡度的总和
递归中做的事情：
1.返回当前节点值与其左右子树的所有节点和
2.计算当前节点的坡度，加入到答案中
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

var findTilt = function(root) {
  function helper(node) {
    if (node === null) return 0;
    
    let left = helper(node.left),
        right = helper(node.right);
    ans += Math.abs(left - right);
    return node.val + left + right;
  }
  
  let ans = 0;
  helper(root);
  
  return ans;
};
```