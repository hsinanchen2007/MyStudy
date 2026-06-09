### 解题思路
此处撰写解题思路
二叉树遍历还是不太了解如何实现的，只是知道这个方法的使用规律，前中后序都是根据【根】的位置来说的，前序则跟在前再左右；中序则左中右，后序则左右中，中都指的是【根】的位置。遍历时，将出口判断条件写出即root===null时跳出遍历。根据【根】的位置，写出响应的回调。这道题为中序遍历，即先遍历左节点，根入栈，遍历右节点。
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
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    var res = []
    help(root, res)
    function help(root, res) {
        if (root !== null) {
            help(root.left, res)
            res.push(root.val)
            help(root.right, res)
        }
    }
    return res
};
```