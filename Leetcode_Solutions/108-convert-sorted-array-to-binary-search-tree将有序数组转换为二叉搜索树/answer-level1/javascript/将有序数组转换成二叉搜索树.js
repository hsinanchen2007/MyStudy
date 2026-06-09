1、始终选择中间位置或中间位置靠左的元素作为根节点

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
  return helper(nums,0,nums.length-1);
};
const helper = function(nums,l,r) {
    if(l > r) return null;
    let m = Math.floor((l+r)/2);
    let root = new TreeNode(nums[m]);
    root.left = helper(nums,l,m-1);
    root.right = helper(nums,m+1,r);
    return root;
}
```

2、选择中间任意位置
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
  return helper(nums,0,nums.length-1);
};
const helper = function(nums,l,r) {
    if(l > r) return null;
    let m = Math.floor((l+r)/2);
    if((l+r) % 2) { // 不为0的时候才是偶数
        m += Math.round(Math.random()); // 拿0或者1
    }
    let root = new TreeNode(nums[m]);
    root.left = helper(nums,l,m-1);
    root.right = helper(nums,m+1,r);
    return root;
}
```