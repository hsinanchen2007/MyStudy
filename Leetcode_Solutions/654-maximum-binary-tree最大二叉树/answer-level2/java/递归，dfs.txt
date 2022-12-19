### 解题思路
此处撰写解题思路

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
        if (null == nums || nums.length == 0) {
            return null;
        }
        return dfs(nums,0,nums.length - 1);
        
    }

    public TreeNode dfs(int [] nums, int start, int end) {
        if (start > end) {
            return null;
        }
        int maxIndex = findMaxInArray(nums,start,end);
        TreeNode root = new TreeNode(nums[maxIndex]);
        root.left = dfs(nums,start,maxIndex - 1);
        root.right = dfs(nums,maxIndex + 1,end);
        return root;
    }

    public int findMaxInArray(int[] nums,int start,int end) {
        int index = start;
        int maxVal =nums[start];
        for (int i = start; i <= end; i++) {
            if (nums[i] > maxVal) {
                index = i;
                maxVal = nums[i];
            }
        }
        return index;
    }
}
```