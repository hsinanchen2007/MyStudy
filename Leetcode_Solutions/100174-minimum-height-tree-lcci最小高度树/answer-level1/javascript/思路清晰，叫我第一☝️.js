### 解题思路
dfs专练

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
var sortedArrayToBST = function(nums) {
    if(nums.length == 0) return null

    var mid = Math.floor(nums.length / 2)

    var root = {
        val: nums[mid],
        left: null,
        right: null
    }

    if(nums.length == 1) return root

    root.left = sortedArrayToBST(nums.slice(0,mid))
    root.right = sortedArrayToBST(nums.slice(mid+1))

    return root
};
```