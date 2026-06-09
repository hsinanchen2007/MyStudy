```
import javafx.util.Pair;

class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null) return 0;
        Queue<Pair<TreeNode,Integer>> queue = new LinkedList<Pair<TreeNode, Integer>>();
        queue.add(new Pair<TreeNode, Integer>(root, 1));
        int curDepth = 0;
        while(!queue.isEmpty()){
            Pair<TreeNode, Integer> cur = queue.poll();
            TreeNode curNode = cur.getKey();
            curDepth = cur.getValue();
            if(curNode.left != null){
                queue.add(new Pair<TreeNode, Integer>(curNode.left, curDepth+1));
            }
            if(curNode.right != null){
                queue.add(new Pair<TreeNode, Integer>(curNode.right, curDepth+1));
            }
        }
        return curDepth;
    }
}
```
