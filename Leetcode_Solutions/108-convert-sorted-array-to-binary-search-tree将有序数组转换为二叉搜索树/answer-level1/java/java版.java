### 解题思路
找到数组中的中间值作为根节点。中间值的左边为左子树，右边为右子树。

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
    int []nums;
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums==null) return null;
        this.nums=nums;
        return helper(0,nums.length-1);
    }
    public TreeNode helper(int start,int end){
        if(start>end) return null;
        int mid=(start+end)/2;
        TreeNode root=new TreeNode(nums[mid]);
        root.left=helper(start,mid-1);
        root.right=helper(mid+1,end);
        return root;
    }
}
```