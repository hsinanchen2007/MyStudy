# 递归

``` JavaScript
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
    // 逢空返回null
    if(!root) return null;
    // 节省时间不用再去反转最后的子节点
    if(root.left || root.right) {
        let temp = root.left;
        root.left = root.right;
        root.right = temp;
        // 递归遍历左右子树
        invertTree(root.left)
        invertTree(root.right)
    }
    return root;
};
```