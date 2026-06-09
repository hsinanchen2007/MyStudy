执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.66%
的用户
内存消耗 :
38.9 MB
, 在所有 Java 提交中击败了
30.21%
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
    public boolean isValidBST(TreeNode root) {
        return get(root,null,null);
    }
    private boolean get(TreeNode root,TreeNode p,TreeNode pp){
        if(root==null)return true;
        if(root.right==null&&root.left==null)return true;
       
        if(p!=null&&p.left==root){
            if(root.left!=null&&root.left.val>=p.val){
                return false;
            }
            if(root.right!=null&&root.right.val>=p.val){
                return false;
            }
        }
        if(p!=null&&p.right==root){
            if(root.left!=null&&root.left.val<=p.val){
                return false;
            }
            if(root.right!=null&&root.right.val<=p.val){
                return false;
            }
        }
        if(pp!=null&&pp.left==p&&root.right!=null&&root.right.val>=pp.val){
            return false;
        }
        if(pp!=null&&pp.right==p&&root.left!=null&&root.left.val<=pp.val){
            return false;
        }
        if(root.left!=null&&root.left.val>=root.val){
            return false;
        } 
         if(root.right!=null&&(root.right.val<=root.val)){
            return false;
        } 
        return get(root.left,root,p)&&get(root.right,root,p);
    }
}
```
