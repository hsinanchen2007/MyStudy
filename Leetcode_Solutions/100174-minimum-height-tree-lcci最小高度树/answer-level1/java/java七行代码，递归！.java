### 解题思路
找出中间值，中间值左边的递归为左子树，中间值右边的递归为右子树。
递归终止条件为nums.length=0；

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
        if(nums.length==0)
        {     return null;                   }
        int mid=nums.length/2;
        TreeNode root=new TreeNode(nums[mid]);
        root.left=sortedArrayToBST(Arrays.copyOfRange(nums,0,mid));
        root.right=sortedArrayToBST(Arrays.copyOfRange(nums,mid+1,nums.length));
        return root;
    }
}
```