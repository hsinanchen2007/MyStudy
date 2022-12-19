```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string[]}
 */
var recur = function (root, res, cur) {
    // 递归返回条件 1.  如果节点为空
    if (root === null) return
    // 递归返回条件 2.  如果节点为叶子节点 已经找到了一条路径
    if (root.left === null && root.right === null) {
        // 将路径存入数组
        cur += root.val
        res.push(cur)
        return
    } else {
        // 非叶子节点 加’->‘表示
        cur += root.val + '->'

    }
    // 递归左右子树
    recur(root.left, res, cur)
    recur(root.right, res, cur)
}
var binaryTreePaths = function(root) {
    // 如果根节点为空 直接返回
    if (root === null) return []
    let res = [],cur = ''
    // 递归
    recur(root, res,cur)
    return res
};
```
