层次遍历，保存每层的最大值，并添加到结果中。

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
    public List<Integer> largestValues(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        List<Integer> res = new LinkedList<>();
        // Abnormal
        if(root == null) return res;
        queue.add(root);
        while(!queue.isEmpty()){
            int maxValue = Integer.MIN_VALUE;
            int count = queue.size();
            while(count-- >0){
                TreeNode tmpNode= queue.poll();
                if(tmpNode.left != null){
                    queue.add(tmpNode.left);
                }
                if(tmpNode.right != null){
                    queue.add(tmpNode.right);
                }
                if(tmpNode.val > maxValue) maxValue = tmpNode.val;
            }
            res.add(maxValue);
        }
        return res;
    }
}



```
