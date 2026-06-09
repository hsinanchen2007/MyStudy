### 解题思路
没什么特别的，直接将数组分成三部分，中间的数值为根节点，左边数组给左边，右边数组给右边。

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
   public TreeNode sortedArrayToBST(int[] nums) {
        return bst(nums);
    }
    public  TreeNode bst(int[] nums){
        if(nums.length==0) return null;
        TreeNode root = new TreeNode(nums[nums.length/2]);
        root.left=bst(Arrays.copyOfRange(nums,0,nums.length/2));//0-1
        root.right = bst(Arrays.copyOfRange(nums,nums.length/2+1,nums.length));//3-4
        return root;
    }
}
```