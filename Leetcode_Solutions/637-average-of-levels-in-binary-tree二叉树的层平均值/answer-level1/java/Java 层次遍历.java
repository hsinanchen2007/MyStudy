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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> rlist = new LinkedList<>();
        List<TreeNode> treeNodeList = new LinkedList<>();
        treeNodeList.add(root);
        while(!treeNodeList.isEmpty()){
            int size = treeNodeList.size();
            double levelSum = 0;
            for(int i = 0;i < size;i++){
                TreeNode node = treeNodeList.remove(0);
                levelSum += node.val;
                if(node.left!=null) treeNodeList.add(node.left);
                if(node.right!=null) treeNodeList.add(node.right);
            }
            rlist.add(levelSum / size);
        }
        return rlist;
    }
}
```