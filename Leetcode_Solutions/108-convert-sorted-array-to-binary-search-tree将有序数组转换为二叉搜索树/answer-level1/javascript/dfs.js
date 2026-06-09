### 解题思路
dfs

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
class TreeNode {
    constructor(val) {
        this.val = val
        this.left = this.right = null
    }
}
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    if(!nums.length) return null
    // let mid = Math.ceil(nums.length / 2)
    function dfs(left, right){
        if(left > right) return null
        let mid = Math.floor((left + right) / 2)
        let cur = new TreeNode(nums[mid])
        // console.log(cur, mid)
        cur.left = dfs(left, mid - 1)
        cur.right = dfs(mid + 1, right)
        return cur
    }
    return dfs(0, nums.length - 1)
};
```