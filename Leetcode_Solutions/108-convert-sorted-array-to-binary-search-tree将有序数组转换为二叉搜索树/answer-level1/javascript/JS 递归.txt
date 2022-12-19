```js
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

function toTreeNode(arr, left, right) {
    let mid = Math.floor((right + left) / 2);
    let node = new TreeNode(arr[mid]);
    if (left === right) return node;
    node.right = toTreeNode(arr, mid + 1, right);
    if (right - left === 1) return node;
    node.left = toTreeNode(arr, left, mid - 1);
    return node;
}
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    if (nums.length === 0) {
        return null
    }

    return toTreeNode(nums, 0, nums.length - 1);

};
```
