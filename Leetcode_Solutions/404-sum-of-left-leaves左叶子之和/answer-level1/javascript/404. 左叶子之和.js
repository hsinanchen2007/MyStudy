### 解题思路

- 如果找到左叶子节点，这时候左边没法继续走下去了，那么递归右子树
- 否则递归左右子树

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
var sumOfLeftLeaves = function(root) {
    if (!root) {
        return 0
    }
    let { left, right } = root
    if (left && !left.left && !left.right) {
        return left.val + sumOfLeftLeaves(right)
    }
    return sumOfLeftLeaves(left) + sumOfLeftLeaves(right)
};
```