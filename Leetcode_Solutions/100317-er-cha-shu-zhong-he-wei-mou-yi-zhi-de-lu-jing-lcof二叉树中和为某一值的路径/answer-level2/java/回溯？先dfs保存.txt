### 解题思路
此处撰写解题思路

### 代码
执行用时 :
1 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
40.2 MB
, 在所有 Java 提交中击败了
100.00%
的用户
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
        List<Integer> tmp = new ArrayList<>();
        List<List<Integer>> res = new ArrayList<>();
        dfs(root, tmp, res, sum);        
        return res;
    }
    private void dfs(TreeNode root, List<Integer> tmp, List<List<Integer>> res, int sum){
        if (root == null) return;
        sum -= root.val;
        tmp.add(root.val);
        if (sum == 0 && root.left == null && root.right == null){
            res.add(new ArrayList<Integer>(tmp));
        }
        dfs(root.left, tmp, res, sum);
        dfs(root.right, tmp, res, sum);
        tmp.remove(tmp.size() - 1);
    }
    
}
```