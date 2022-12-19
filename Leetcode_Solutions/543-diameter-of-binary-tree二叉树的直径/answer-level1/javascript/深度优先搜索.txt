### 解题思路
对于每个树的节点，以它为 root 的直径为 左子树的深度 + 右子树的深度 + 1

遍历一遍该树，更新每次的最大直径和每个节点的深度

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
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    let res = 1;
    const getDepth = (node) => {
        if (!node) return 0;
        const l = getDepth(node.left);
        const r = getDepth(node.right);
        res = Math.max(res, l + r + 1);
        return Math.max(l, r) + 1;
    }
    getDepth(root);
    return res - 1;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(logN)