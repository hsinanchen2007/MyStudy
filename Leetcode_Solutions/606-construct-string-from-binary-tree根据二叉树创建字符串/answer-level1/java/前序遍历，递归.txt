最近提交结果：
通过
显示详情 
执行用时 :
27 ms
, 在所有Java提交中击败了
49.90%
的用户
内存消耗 :
49.6 MB
, 在所有Java提交中击败了
58.65%
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
   
    public String tree2str(TreeNode t) {
        if(t==null)return "";
        
        return print(t);
    }
    
    private String print(TreeNode n){
         StringBuffer sb = new StringBuffer();
        sb.append(n.val);
        if(n.left!=null){
            sb.append("(");
            sb.append(print(n.left));
            sb.append(")");
        }else if(n.left==null && n.right!=null){
            sb.append("()");
        }
        if(n.right!=null){
            sb.append("(");
            sb.append(print(n.right));
            sb.append(")");
        }
        return sb.toString();
    }
}
```