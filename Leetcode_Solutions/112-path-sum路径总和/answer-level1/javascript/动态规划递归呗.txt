### 解题思路
![image.png](https://pic.leetcode-cn.com/67dc9459a430a4afe9163f24361f600942e2726ea1a1ab96ca433cbd11801b21-image.png)

递归遍历，就酱。。

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
    if (!root) {
        return false;
    } else if (!root.left && !root.right && root && root.val === sum) {
        return true;
    } else if (!root.left && !root.right && root.val != sum) {
        return false;
    } else if (!root.left && root.right) {
        return (hasPathSum(root.right, sum - root.val));
    } else if (root.left && !root.right) {
        return (hasPathSum(root.left, sum - root.val));
    } else {
        return (hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val));
    }
};
```