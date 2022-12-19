### 解题思路
首先找出数组中最大值所在的索引值max_i，然后构建根节点root。
在[0, max_i]范围内递归构建左子树。
在[max_i+1, length]范围内递归构建右子树。
最后返回根节点root.
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
        return construct(nums, 0, nums.length);
    }
    private TreeNode construct(int[] nums, int l, int r){
        if(l == r) return null;
        int max_i = max(nums, l, r);
        TreeNode root = new TreeNode(nums[max_i]);
        root.left = construct(nums, l, max_i);
        root.right = construct(nums, max_i+1, r);
        return root;
    }
    private int max(int[] nums, int l, int r){
        int max_i = l;
        for(int i = l; i < r; i++){
            if(nums[max_i] < nums[i])
                max_i = i;
        }
        return max_i;
    }
}
```