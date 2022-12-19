使用leetcode模拟面试的时候碰到的题目，作为简单题感觉稍微复杂了些
最外层做DFS遍历，每次DFS到新节点，递归求和。
时间复杂度应该是N*logN，遍历了所有节点N，每个节点求和logN
```
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
    int count=0;
    public int pathSum(TreeNode root, int sum) {
        if(root == null) return 0;
        dfs(root,sum);
        pathSum(root.left,sum);
        pathSum(root.right,sum);
        return count;
    }

    public void dfs(TreeNode root,int target){
        if(root == null) return;
        if(root.val == target){
            count++;
        }
        dfs(root.left,target-root.val);
        dfs(root.right,target-root.val);
    }
}
```
