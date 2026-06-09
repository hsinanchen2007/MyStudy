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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        LinkedList<List<Integer>> result= new LinkedList<>();
        List<TreeNode> first = new ArrayList<>();
        if(root!=null){
            first.add(root);
        }
        while(first.size()>0){
            first = traverse(result,first);
        }
        return result;
    }
    
    private List<TreeNode> traverse(LinkedList<List<Integer>> result, List<TreeNode> first){
        List<Integer> temp = new ArrayList<Integer>();
        List<TreeNode> second = new ArrayList<>();
        for(int i = 0 ;i<first.size();i++){
            TreeNode tn = first.get(i);
            if(tn.left!=null){
                second.add(tn.left);
            }
            if(tn.right!=null){
                second.add(tn.right);
            }
            temp.add(tn.val);
        }
        if(temp.size()>0){
            result.addFirst(temp);
        }
        return second;
    }
}
```
