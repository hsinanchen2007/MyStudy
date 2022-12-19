### 解题思路

- 收集 ``二叉树`` 的叶子结点值，之后把它删除
- 重复上一过程，直到 ``二叉树`` 为空

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
 * @return {number[][]}
 */
var findLeaves = function(root) {
    const helper = (root) => {
        if (!root) {
            return null
        }
        if (!root.left && !root.right) {
            res[i].push(root.val)
            return null
        }
        root.left = helper(root.left)
        root.right = helper(root.right)
        return root
    }
    let res = []
    let i = 0
    while (root) {
        res[i] = []
        root = helper(root)
        i++
    }
    return res
};
```