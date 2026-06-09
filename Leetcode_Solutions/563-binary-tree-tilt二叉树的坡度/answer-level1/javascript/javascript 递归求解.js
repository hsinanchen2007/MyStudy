### 解题思路
递归的求解

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
var findTilt = function(root) {
    let sum = 0
    function getSum (root) {
        if (!root) {
            return 0
        }
        const leftSum = getSum(root.left)
        const rightSum = getSum(root.right)
        sum += Math.abs(leftSum - rightSum)
        return leftSum + rightSum + root.val
    }
    getSum(root)
    return sum
};
```