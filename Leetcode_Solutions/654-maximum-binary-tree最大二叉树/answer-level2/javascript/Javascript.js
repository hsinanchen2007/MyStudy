### 解题思路
找出最大值（root），然后通过分治得到left和right，最后递归

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
 * @param {number[]} nums
 * @return {TreeNode}
 */
var constructMaximumBinaryTree = function(nums) {
    if (!nums.length) {
        return null
    }

    // let max = 0
    let idx = 0
    let max = nums.reduce((initVal, currVal) => {
        if (initVal < currVal) {
            initVal = currVal
        }
        return initVal
    }, 0)

    const maxIndex = nums.indexOf(max)
    const left = nums.slice(0, maxIndex)
    const right = nums.slice(maxIndex + 1)

    const root = new TreeNode(max)
    root.left = constructMaximumBinaryTree(left)
    root.right = constructMaximumBinaryTree(right)

    return root
};
```