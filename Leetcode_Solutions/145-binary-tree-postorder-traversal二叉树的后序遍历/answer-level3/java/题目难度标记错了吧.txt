### 解题思路
题目难度标记错了吧

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
    public List<Integer> postorderTraversal(TreeNode root) {

          ArrayList<Integer> list = new ArrayList<>();
        dfs(list,root);
        return list;

    }

    private void dfs(ArrayList<Integer> list, TreeNode root) {
        //前序，先遍历根节点，然后遍历左节点，然后遍历右节点
        if (root==null) return;
        
        dfs(list,root.left);
        dfs(list,root.right);
        list.add(root.val);
    }
}
```