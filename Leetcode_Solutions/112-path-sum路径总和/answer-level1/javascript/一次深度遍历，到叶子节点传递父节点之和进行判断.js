### 解题思路
代码有注释

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
 * @param {number} psum 祖先节点计算和
 * @return {boolean}
 */
var hasPathSum = function(root, sum, psum) {
    if(!root) {
        return false
    }
    if(!psum) {
        psum = 0
    }
    if(root.left && root.right) {
        // 双子树，取并集
        return hasPathSum(root.left, sum, psum + root.val) ||
            hasPathSum(root.right, sum, psum + root.val)
    } else if(root.left) {
        // 只有左子树
        return hasPathSum(root.left, sum, psum + root.val)
    } else if(root.right) {
        // 只有右子树
        return hasPathSum(root.right, sum, psum + root.val)
    } else {
        // 叶子节点
        if(psum + root.val === sum) {
            return true
        }
        return false
    }
};
```