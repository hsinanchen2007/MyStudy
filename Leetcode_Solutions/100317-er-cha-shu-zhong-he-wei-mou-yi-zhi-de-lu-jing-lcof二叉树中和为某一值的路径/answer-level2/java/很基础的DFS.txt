### 解题思路
没啥思路，就是dfs回溯。

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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> results = new ArrayList<>();
        if(root == null) {
            return results;
        }
        
        List<Integer> subsets = new ArrayList<>();
        subsets.add(root.val);
        dfs(root, sum - root.val, subsets, results);
        
        return results;
    }
    
    private void dfs(TreeNode root, int sum, List<Integer> subsets, List<List<Integer>> results) {
        if(root != null && root.left == null && root.right == null && sum == 0) {
            results.add(new ArrayList(subsets));
        }
        
        if(root.left != null) {
            subsets.add(root.left.val);
            dfs(root.left, sum - root.left.val, subsets, results);
            subsets.remove(subsets.size() - 1);
        }
        
        if(root.right != null) {
            subsets.add(root.right.val);
            dfs(root.right, sum - root.right.val, subsets, results);
            subsets.remove(subsets.size() - 1);
        }
    }
}
```