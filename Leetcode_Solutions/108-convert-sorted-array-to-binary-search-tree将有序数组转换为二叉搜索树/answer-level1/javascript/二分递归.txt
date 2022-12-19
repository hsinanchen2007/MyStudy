## 第一版，递归构建每个子树。将数组从最中间项分割得到三个部分：子数组1，中间项，子数组2。将中间项作为当前节点的val，对子数组1和子数组2分别递归执行原方法，得到的两个子树分别作为上一个节点的左子树与右子树
> 96ms,37.8M
```javascript []
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
  if (!nums.length) return null;
  const root = new TreeNode(null);

  if(nums.length > 1) root.left = sortedArrayToBST(nums.splice(0, nums.length / 2));
  root.val = nums[0];
  root.right = sortedArrayToBST(nums.splice(1));
  return root;
};
```