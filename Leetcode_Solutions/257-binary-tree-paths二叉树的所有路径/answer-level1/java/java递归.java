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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> list = new ArrayList<String>();
        if(root==null){
            return list;
        }else{
            String s = root.val+"";
            if(root.right==null&&root.left==null){
                list.add(s);
            }else{
                 putPaths(list,s ,root.left);
                 putPaths(list,s ,root.right);
            }
        }
        return list;
    }
    
    public void putPaths(List<String> list,String s ,TreeNode node){
        String currentS = "";
        if(node!=null){
            currentS = s + "->"+node.val;
            if(node.left==null&&node.right==null){
                list.add(currentS);
            }else{
                putPaths(list,currentS,node.left);
                putPaths(list,currentS,node.right);
            }
        }
    }
}
```
