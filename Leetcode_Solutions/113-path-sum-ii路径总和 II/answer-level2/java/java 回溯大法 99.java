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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result = new ArrayList<>();
        if(root==null){
            return result;
        }
        pathSum(result,new ArrayList<Integer>(),0,root,sum);
        return result;
    }
    
    private void pathSum(List<List<Integer>> result, List<Integer> curr, int currSum, TreeNode root, int sum){
        if(root!=null){
            if(root.left==null&&root.right==null){
                if(currSum+root.val==sum){
                    curr.add(root.val);
                    result.add(new ArrayList<Integer>(curr));
                    curr.remove(curr.size()-1);
                }
            }else{
                curr.add(root.val);
                currSum += root.val;
                pathSum(result,curr,currSum,root.left,sum);
                pathSum(result,curr,currSum,root.right,sum);
                currSum -= root.val;
                curr.remove(curr.size()-1);
            }
        }
       
    }
}
```
