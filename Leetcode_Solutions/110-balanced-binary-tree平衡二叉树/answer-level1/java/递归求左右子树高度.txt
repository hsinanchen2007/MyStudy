
执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
99.15%
的用户
内存消耗 :
39.5 MB
, 在所有 Java 提交中击败了
24.53%
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
     
    public boolean isBalanced(TreeNode root) {
        if(root==null)return true;
        return get(root);
    }
    public boolean get(TreeNode tn){
        if(tn==null){
            return true;
        } 
        int l = geth(tn.left);
        int r = geth(tn.right);
        if(Math.abs(l-r)>1)return false;
        return get(tn.right)&&get(tn.left);
    }
    private int geth(TreeNode tn){
        if(tn==null){
            return 0;
        }
        if(tn.left==null&&tn.right==null){
            return 1;    
        }
        return Math.max(geth(tn.left),geth(tn.right))+1;
    }
}
```
