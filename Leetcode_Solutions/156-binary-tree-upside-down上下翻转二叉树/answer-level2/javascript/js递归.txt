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
var upsideDownBinaryTree = function(root) {
    if(!root) return root;
    if(!root.left) return root;
    let newRoot;
    let revert = (node) => {
        if(!node.left.left) {
            newRoot = new TreeNode(node.left.val);
            if(node.right) {
                newRoot.left = new TreeNode(node.right.val);
            }
            newRoot.right = new TreeNode(node.val);
            return newRoot.right;
        }
        let after = revert(node.left);
        if(node.right) {
            after.left = new TreeNode(node.right.val);
        }
        after.right = new TreeNode(node.val);
        return after.right;
    }
    revert(root);
    return newRoot;
};
```