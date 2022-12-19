### 解题思路
分为几种情况：1、p有右子树，返回右子树最左节点
2、p无右子树，用stack记录从根节点到p的所有父节点，从p开始向上找第一个是父节点左孩子的节点，返回该父节点。
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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        Stack<TreeNode>stack=new <TreeNode>Stack();
        TreeNode t=root;
        if(root==null)
        return null;
        if(p.right!=null)
        {
            p=p.right;
            while(p.left!=null)
            p=p.left;
            return p;
        }
        while(t!=null&&t.val!=p.val)
        {
            if(t.left==p||t.right==p)
            {
                stack.push(t);
                break;
            }
            stack.push(t);
            if(t.val<p.val)
            t=t.right;
            else if(t.val>p.val)
            t=t.left;
        }
        if(t==null)
        return null;
        while(!stack.isEmpty())
        {
            t=stack.pop();
            System.out.println(t.val);
            if(t.left==p)
            {
                return t;
            }
            else
            {
                p=t;
            }
        }
        return null;
    }
}
```