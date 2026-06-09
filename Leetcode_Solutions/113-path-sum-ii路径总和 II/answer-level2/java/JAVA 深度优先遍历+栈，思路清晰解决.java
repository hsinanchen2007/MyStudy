### 解题思路
JAVA 深度优先遍历+栈，思路清晰解决

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

    public void dfs(TreeNode root,Stack<Integer> path,int sum,int target,List<List<Integer>> results) {

        if(root.left== null && root.right == null) {
            if(sum == target) {
                results.add((List<Integer>)path.clone());
                // System.out.println(path);
            }
            return;
        }
        if(root.left!=null) {
            path.push(root.left.val);
            dfs(root.left,path,sum+root.left.val,target,results);
            path.pop();
        }

        if(root.right!=null) {
            path.push(root.right.val);
            dfs(root.right,path,sum+root.right.val,target,results);
            path.pop();
        }
    }
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> results = new LinkedList<>();
        if(root == null) {
            return results;
        }
        
        Stack<Integer> path = new Stack<>();
        path.push(root.val);
        dfs(root, path,root.val,sum,results);
        return results;
    }
}
```