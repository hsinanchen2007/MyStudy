遍历一遍生成二叉树
中序遍历二叉树一遍
**代码优化差,速度慢,但希望能提供一种思路**
```java
class Solution {
    int max = 1;
    int count = 0;
    
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0)
            return 0;
        if(nums.length == 1)
            return 1;
        TreeNode root = new TreeNode(nums[0]);
        for(int i = 1; i < nums.length; i++)
            insert(root, nums[i]);
        dfs(root, 0);
        return max;
    }
    
    private int dfs(TreeNode root, int prev) {
        if(root.left != null)
            prev = dfs(root.left, prev);
        
        if(root.val == prev + 1) {
            count++;
            max = Math.max(max, count);
        }
        else 
            count = 1;
        prev = root.val;
        //System.out.print(prev);
        
        if(root.right != null)
            prev = dfs(root.right, prev);
        
        return prev;
    }
    
    private void insert(TreeNode root, int val) {
        while(true) {
            if(val > root.val) {
                if(root.right == null) {
                    root.right = new TreeNode(val);
                    return;
                }
                root = root.right;
            }
            else if(val < root.val) {
                if(root.left == null) {
                    root.left = new TreeNode(val);
                    return;
                }
                root = root.left;
            }
            else
                return;
        }
    }
}
```
