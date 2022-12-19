
### 题目描述

给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：

- 该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
如果不存在祖父节点值为偶数的节点，那么返回 0 。 

### 解题思路

在当前节点中保存父节点的信息，那么就能通过父节点再访问祖父节点。  

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
var sumEvenGrandparent = function(root) {
    function dfs (root, level) {
        if (!root) {
            return
        }
        let { left, right, pre } = root
        // 判断祖父节点在不在
        if (pre && pre.pre) {
            // 如果祖父节点值是偶数，那么加入 sum
            if (pre.pre.val % 2 === 0) {
                sum += root.val
            }
        }
        // 如果左子树存在，保存左子树的父节点信息
        // 之后递归
        if (left) {
            left.pre = root
            dfs(left)
        }
        // 如果右子树存在，保存右子树的父节点信息
        // 之后递归
        if (right) {
            right.pre = root
            dfs(right)
        }
    }
    // sum 是全局变量
    let sum = 0
    dfs(root)
    return sum
};
```