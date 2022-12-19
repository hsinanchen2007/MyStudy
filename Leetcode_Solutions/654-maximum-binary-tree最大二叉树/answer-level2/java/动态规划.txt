### 解题思路

动态规划，大事化小 
1. 从数组中找到最大的那个元素。
2. 最大的元素创建TreeNode，然后左右数组递归调用。

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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return helper(nums,0,nums.length-1);
    }
    public TreeNode helper(int[] nums,int start,int end){
        if(start>end)return null;
        int findMaxIndex = findMaxIndex(nums,start,end);
        TreeNode root = new TreeNode(nums[findMaxIndex]);
        root.left = helper(nums,start,findMaxIndex-1);
        root.right = helper(nums,findMaxIndex+1,end);
        return root;
    }

    public int findMaxIndex(int[] nums,int start,int end ){
        int max = nums[start];
        int maxIndex = start;
        for(int i=start+1;i<=end;i++){
            if(nums[i]>max){
                max = nums[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
}
```