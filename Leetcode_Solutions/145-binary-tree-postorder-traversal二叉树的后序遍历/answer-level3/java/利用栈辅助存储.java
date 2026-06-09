执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
60.14%
的用户
内存消耗 :
35.2 MB
, 在所有 Java 提交中击败了
36.96%
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
    public List<Integer> postorderTraversal(TreeNode root) {
        Stack<TreeNode> sta = new Stack<>();
        List<Integer> list = new ArrayList<>();
        if(root==null)return list;
        sta.push(root);
        while(!sta.isEmpty()){
            TreeNode tn = sta.peek();
            if(tn.left!=null||tn.right!=null){
                if(tn.right!=null){
                    sta.push(tn.right);
                    tn.right=null;
                }
                if(tn.left!=null){
                    sta.push(tn.left);
                    tn.left=null;
                }
            }else{
                list.add(sta.pop().val);
            }
        }
        return list;
    }
}
```
