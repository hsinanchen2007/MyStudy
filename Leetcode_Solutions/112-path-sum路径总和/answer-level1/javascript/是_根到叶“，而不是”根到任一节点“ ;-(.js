### 解题思路
![image.png](https://pic.leetcode-cn.com/66905f1f911a2f8c1b9a76243139933342b37546eee0d32fb603bc0207ccf5c0-image.png)

用三元可读性更好些，似乎。。。

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
    } else {
        return ((root.left ? hasPathSum(root.left, sum - root.val) : false) || (root.right ? hasPathSum(root.right, sum - root.val) : false));
    }
};
```