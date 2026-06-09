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
    public int pathSum(TreeNode root, int sum) {
        if(root==null){
            return 0;
        }
        List<Integer> current = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();

        traverse(root,current,result,sum);
        return result.size()+pathSum(root.left,sum)+pathSum(root.right,sum);
    }

    private void traverse(TreeNode root, List<Integer> current,List<List<Integer>> result, int sum){
        if(root==null){
            return;
        }
        
        current.add(root.val);
        int nextSum = sum-root.val;
        if(nextSum==0){
            result.add(new ArrayList<>(current));
        }
            
        traverse(root.left,current,result,nextSum);
        traverse(root.right,current,result,nextSum);
        current.remove(current.size()-1);
        
    }
    


}
```
