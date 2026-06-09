```
var sortedArrayToBST = function (nums) {
  if (nums.length == 0) return null;
  let cen = Math.floor(nums.length / 2)
  let node = new TreeNode(nums[cen])
  node.left = sortedArrayToBST(nums.slice(0, cen))
  node.right = sortedArrayToBST(nums.slice(cen + 1))
  return node;
};
```


去中间数，再递归左子树和右子树
