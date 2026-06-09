### 解题思路
递归还是最容易想到的办法。由于分层遍历，所以需要一个index 来记录每个节点所在的层级，这就需要在递归时传递当前层级。另外为了避免全局变量，就把levels作为参数传递了。代码如下：

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
    public void helper(TreeNode node, int level, List<List<Integer>> levels){
        if(levels.size() == level) levels.add(new ArrayList<>());

        levels.get(level).add(node.val);

        if(node.left != null)
            helper(node.left, level+1, levels);

        if(node.right != null)
            helper(node.right, level+1, levels);
    }


    public List<List<Integer>> levelOrder(TreeNode root){
        List<List<Integer>> levels = new ArrayList<>();
        if(root == null) return levels;
        helper(root, 0, levels);

        return levels;
    }
}
```