### 解题思路
树本身就是一个递归结构，所以在利用树的时候要充分利用递归结构。

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
        int length=nums.length;
        if(length==0) return null;
        int a=length/2;
        TreeNode root=new TreeNode(nums[a]);

        root.left=sortedArrayToBST(Arrays.copyOfRange(nums,0,a));
        root.right=sortedArrayToBST(Arrays.copyOfRange(nums,a+1,length));
        return root;

    }
}
```