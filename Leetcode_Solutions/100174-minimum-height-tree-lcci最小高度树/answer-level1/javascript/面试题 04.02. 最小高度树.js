### 解题思路

构造最小高度的 ``二叉搜索树`` 思路比较简单，只要满足左右子树高度相等即可:

- 每次取 ``nums`` 的中位数作为 ``root`` 节点的值
- 递归左右子树

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
    const helper = (left, right) => {
        if (left >= right) {
            return null
        }
        let mid = Math.floor((left + right) >> 1)
        let root = new TreeNode(nums[mid])
        root.left = helper(left, mid)
        root.right = helper(mid + 1, right)
        return root
    }
    return helper(0, nums.length)
};
```