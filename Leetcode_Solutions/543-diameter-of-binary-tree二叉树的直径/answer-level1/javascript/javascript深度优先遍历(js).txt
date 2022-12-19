任意两个节点之间的边数都可能是最大直径

最大的直径不一定包括根节点

这道题很容易有的误区就是：从根节点出发，找到左边数的最大深度 leftDepth，再找到右边树的最大深度 rigthDepth

然后 return leftDepth+rigthDepth + 1（如果二叉树的根节点深度为0的话）

情况并不是这样，因为最大值不一定要包含根节点。

## 解题思路

从上面的分析可知，最大值不一定包含根节点，但是一定是：经过一个节点，该节点左右子树的最大深度之和 +1+1（二叉树的根节点深度为 00）
于是，可以使用 DFS，找出所有节点的最大直径，在取出最大值 res;

定义一个全局变量 res，用来记录最大直径
使用 dfs(root) 遍历所有的节点，dfs(root) 的作用是：找出以 root 为根节点的二叉树的最大深度

将根节点的深度定义为 11（和上面分析的深度定义不一样）
root 为跟节点的最大深度为 Math.max(leftDepth,rigthDepth) + 1
res 取值为以经过 root，左右子树的最大深度之和 leftDepth + rigthDepth（不用加 11，是因为根节点的深度是 11）
通过递归，找到 res 的最大值

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
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    let res = 0;

    function depth(node) {
        if (!node) {
            return 0;
        }
        const left = depth(node.left);
        const right = depth(node.right);
        res = Math.max(res, left + right);
        return Math.max(left, right) + 1;
    }

    depth(root);
    
    return res;
};

```