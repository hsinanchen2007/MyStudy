有两个需要注意的是

1. 每个节点只能做一次根节点
2. 找到一条路径之后，需要沿着这条路径继续往下找，因为沿着这条路径可能还会出现相加等于m的情况

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
 * @param {number} sum
 * @return {number}
 */
var pathSum = function(root, sum) {
    let count = 0;
    const findRoute = (current, currentSum) => {
        if (!current) {
            return;
        }
        if (!current.isVisted) {
            current.isVisted = true;
            current.left && findRoute(current.left, 0);
            current.right && findRoute(current.right, 0);
        }
        let val = currentSum + current.val;
        if (currentSum + current.val === sum) {
            count++;
        }
        current.left && findRoute(current.left, val);
        current.right && findRoute(current.right, val);
    }
    findRoute(root, 0);
    return count;
};

```