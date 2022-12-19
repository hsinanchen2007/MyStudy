### 解题思路

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
// class Solution {
//     private List<Integer> ans=new ArrayList<>();
//     public List<Integer> preorderTraversal(TreeNode root) {
//         preorder(root);
//         return ans;
//     }
//     public void preorder(TreeNode head){
//         if(head==null)
//         return;
//         ans.add(head.val);
//         if(head.left!=null)
//          preorder(head.left);
//         if(head.right != null)
//          preorder(head.right);
//         return;
//     }
// }
class Solution {//非递归
    public List<Integer> preorderTraversal(TreeNode root) {
        Stack<TreeNode> stack=new Stack<>();
        List<Integer> ans=new ArrayList<>();
        if(root==null)
        return ans;
        stack.push(root);
        while(!stack.isEmpty())
        {
            TreeNode p = stack.pop();
            ans.add(p.val);
            if(p.right!=null)
             stack.push(p.right);
            if(p.left!=null)
             stack.push(p.left);        
        }
        return ans;
    }
}
```