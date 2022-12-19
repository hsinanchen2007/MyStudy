```
class Solution {
    List<List<Integer>> levels = new ArrayList<List<Integer>>(); 
    public void helper(TreeNode node, int level) {
        // start the current level
        if (levels.size() == level)
            levels.add(new ArrayList<Integer>());
         // fulfil the current level
         levels.get(level).add(node.val);
         // process child nodes for the next level
         if (node.left != null)
            helper(node.left, level + 1);
         if (node.right != null)
            helper(node.right, level + 1);
    }
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if (root == null) return levels;
        helper(root, 0);
        //只有这句是另外加的
        Collections.reverse(levels);//将集合中的所有对象按倒序排列

        return levels;
    }
}
```
