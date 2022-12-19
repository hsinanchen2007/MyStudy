### 解题思路

由于 ``二叉搜索树`` 的 ``中序遍历`` 结果是「严格递增」的，因此直接判断 ``中序遍历`` 的结果是否是「严格递增」即可。

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
var isValidBST = function(root) {
    const helper = (root) => {
        // 如果遍历到底，那么该二叉树是合法的二叉搜索树
        if (!root) {
            return true
        }
        if (helper(root.left)) {
            // 检查上一个值是否小于当前值
            if (prev < root.val) {
                prev = root.val
                return helper(root.right)
            }
        }
        return false
    }
    let prev = Number.MIN_SAFE_INTEGER
    return helper(root)
};
```