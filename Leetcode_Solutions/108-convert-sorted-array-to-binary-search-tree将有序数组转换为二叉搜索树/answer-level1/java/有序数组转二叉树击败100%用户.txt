### 解题思路 1.根据二叉树的特性，依次对数组折半取值，数组的大小一直在变，故另写一个函数，表明新数组的头尾索引值。


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
        return toBST(nums,0,nums.length-1);
    }
    private TreeNode toBST(int[] nums,int left,int right){
        if(left>right) return null;
        int a=(left+right)/2;
        TreeNode root=new TreeNode(nums[a]);
        root.left=toBST(nums,left,a-1);
        root.right=toBST(nums,a+1,right);
        return root;
    }
}
```