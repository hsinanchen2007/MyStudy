### 解题思路

以下是简单的思路：

- 对比上一个节点的值和当前节点的值，如果不相等，直接返回 ``false``
- 递归左右子树

⚠️注意：这里使用任意能遍历 ``二叉树`` 的方法都行，核心思想是找出不一样的情况。

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
var isUnivalTree = function(root) {
    const helper = (root, prev) => {
        if (!root) {
            return true
        }
        let { left, right, val } = root
        if (val !== prev) {
            return false
        }
        return helper(left, val) && helper(right, val)
    }
    return helper(root, root && root.val)
};
```