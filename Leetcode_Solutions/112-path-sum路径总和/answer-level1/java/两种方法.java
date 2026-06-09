简单的方法：
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
     public boolean hasPathSum(TreeNode root, int sum) {
         if (root == null) {
            return false;
        }

        if (root.val == sum && root.left == null && root.right == null) {
            return true;
        }
        
        return hasPathSum(root.left, sum - root.val) || hasPathSum(root.right, sum - root.val);
    }

}
```

麻烦的方法：
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
     public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }

        List<List<Integer>> res = new ArrayList<>();
        dfs(root, sum, root.val, new ArrayList<>(), res);
        return res.size() > 0;
    }

    private void dfs(TreeNode root, int sum, int sumNow, List<Integer> subsets, List<List<Integer>> res) {
        if (root != null && root.left == null && root.right == null) {
            if (sumNow == sum) {
                res.add(subsets);
            }
        }

        if (root.left != null) {
            sumNow += root.left.val;
            subsets.add(root.left.val);
            dfs(root.left, sum, sumNow, subsets, res);
            sumNow -= root.left.val;
            subsets.remove(subsets.size() - 1);
        }

        if (root.right != null) {
            sumNow += root.right.val;
            subsets.add(root.right.val);
            dfs(root.right, sum, sumNow, subsets, res);
            sumNow -= root.right.val;
            subsets.remove(subsets.size() - 1);
        }
    }
}
```
