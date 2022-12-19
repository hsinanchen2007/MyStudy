执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
59.62%
的用户
内存消耗 :
34.9 MB
, 在所有 Java 提交中击败了
40.72%
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
    List<Integer> list = new ArrayList<>();
    public List<Integer> preorderTraversal(TreeNode root) {
        if(root==null)return list;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
         
        while(!stack.isEmpty()){
            TreeNode tn = stack.pop();
            list.add(tn.val);
            if(tn.right!=null)stack.push(tn.right);
            if(tn.left!=null)stack.push(tn.left);
            
        }
        
        return list;
    }
}
```
