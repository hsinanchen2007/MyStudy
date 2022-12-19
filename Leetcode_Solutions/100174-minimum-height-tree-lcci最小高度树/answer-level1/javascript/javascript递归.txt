### 解题思路
因为是要做平衡树，所以每次取出中间节点做为根节点，根节点左面的做左子树，右面的做右子树。
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
   if(nums.length===0) return null
   let index=parseInt(nums.length/2)
   let nodeVal=nums[index]
   let node=new TreeNode(nodeVal)
   node.left=sortedArrayToBST(nums.slice(0,index))
   node.right=sortedArrayToBST(nums.slice(index+1))
   return node
};
```