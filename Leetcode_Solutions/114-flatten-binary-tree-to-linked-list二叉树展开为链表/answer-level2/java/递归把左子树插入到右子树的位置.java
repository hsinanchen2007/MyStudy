执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
90.29%
的用户
内存消耗 :
36 MB
, 在所有 Java 提交中击败了
81.11%
的用户
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
    public void flatten(TreeNode root) {
        if(root==null)return ;
        get(root);
    }
    
    private List<TreeNode> get(TreeNode root){
       
        List<TreeNode> list = new ArrayList<TreeNode>();
        list.add(root);
        
        if(root.left==null&&root.right==null){
            list.add(root);
            return list;
        }
        
        List<TreeNode> leftl = new ArrayList<TreeNode>();
        if(root.left!=null){
           leftl = get(root.left);
        }
        
        List<TreeNode> rightl = new ArrayList<TreeNode>();
        if(root.right!=null){
           rightl = get(root.right);
        }
        
        if(leftl.isEmpty()){
            list.add(rightl.get(1));
            return list;
        }else if(rightl.isEmpty()){
            root.left=null;
            root.right=leftl.get(0);
            list.add(leftl.get(1));
            return list;
        }else{
            //both exist
            root.left=null;
            root.right=leftl.get(0);
            leftl.get(1).right = rightl.get(0);
            list.add(rightl.get(1));
            return list;
        }
        
    }
}
```
