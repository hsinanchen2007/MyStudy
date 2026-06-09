### 解题思路
- 二叉树的先序遍历:根左右
- 当前节点为空,返回null
- 交换左右子树

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
var mirrorTree = function(root) {
    if(root == null){
        return null
    }
    [[root.left,root.right]] = [[root.right,root.left]]
    mirrorTree(root.left)
    mirrorTree(root.right)
    return root
};
```