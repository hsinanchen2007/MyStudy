    判断一个树是否为二叉搜索树的关键方法是判断它的中序遍历是否递增，可以用非递归法或递归法

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
class Solution {
    public boolean isValidBST(TreeNode root) {
        //判断是否是二叉搜索树的方法就是中序遍历,这里使用栈的方法
       if(root==null)
            return true;
        TreeNode pre=null;
        Stack<TreeNode> stack=new Stack<>();
        while(root!=null)
        {
            stack.push(root);
            root=root.left;
        }
        while(!stack.isEmpty())
        {
            TreeNode Node=stack.pop();
            if(pre!=null&&pre.val>=Node.val)
                return false;
            pre=Node;
            Node=Node.right;
            while(Node!=null)
            {
                stack.push(Node);
                Node=Node.left;
            }
        }
        return true;
    }
}
```