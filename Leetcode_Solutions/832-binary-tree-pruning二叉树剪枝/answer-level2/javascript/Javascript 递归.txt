### 解题思路
后序遍历，通过左右子节点判断该节点是否保留。
确定root是否为叶子结点，如果是并且val == 0，则返回null。
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
var pruneTree = function(root) {
    //常规操作
    if (!root) {
        return null
    }

    //不停的递归
    root.left = pruneTree(root.left)
    root.right = pruneTree(root.right)

    //如果到了叶子节点并且val == 0，则剪掉该节点，返回null，否则返回root
    if (!root.left && !root.right && root.val == 0) {
        return null
    } else {
        return root
    }

    
};
```