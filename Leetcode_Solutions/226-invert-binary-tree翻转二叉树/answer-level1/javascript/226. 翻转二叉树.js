### 解题思路

- 交换当前的 ``left`` 和 ``right`` 节点
- 递归处理左右子树

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
 * @return {TreeNode}
 */
var invertTree = function(root) {
    if (!root) {
        return null
    }
    let { left, right } = root
    root.left = invertTree(right)
    root.right = invertTree(left)
    return root
};
```