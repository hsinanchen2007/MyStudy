### 解题思路
此处撰写解题思路

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
var convertBiNode = function(root) {

    if (!root) return null

    dummyRoot = {}, prev = dummyRoot

    dfs(root)
    return dummyRoot.right
};

const dfs = node => {
    if (node) {
        dfs(node.left)

        node.left = null
        prev.right = node
        prev = node

        dfs(node.right)
    }
}
```