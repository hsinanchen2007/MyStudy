### 解题思路

- 如果当前差值小于上一个的差值，即：$diff < curr$，那么存下当前的差值和 ``root.val``
- 如果 $root.val < target$，那么递归右子树
- 如果 $root.val > target$，那么递归左子树

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
 * @param {number} target
 * @return {number}
 */
var closestValue = function(root, target) {
    const isClosest = (root) => {
        if (!root) {
            return
        }
        let diff = Math.abs(root.val - target)
        if (diff < curr) {
            curr = diff
            res = root.val
        }
        if (root.val < target) {
            isClosest(root.right)
        } else {
            isClosest(root.left)
        }
    }
    let res = root.val
    let curr = Number.MAX_SAFE_INTEGER
    isClosest(root)
    return res
};
```