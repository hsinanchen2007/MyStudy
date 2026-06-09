### 解题思路

- 二进制求和可以表示为: ``next = curr << 1 | root.val``，也可以表示为 ``next = curr * 2 + root.val``
- 递归到叶子节点即可累加

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
var sumRootToLeaf = function(root) {
    const helper = (root, curr) => {
        if (!root) {
            return
        }
        let { left, right, val } = root
        let next = curr * 2 + root.val
        if (!left && !right) {
            sum += next
        }
        helper(left, next)
        helper(right, next)
    }
    let sum = 0
    helper(root, 0)
    return sum % (Math.pow(10, 9) + 7)
};
```