### 解题思路
本题的思路很简单，采用递归方法中序遍历二叉树。将遍历到的节点值存储在列表list中。然后依据列表list的元素顺序构造新的二叉树。

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
    public List<Integer> list=new ArrayList<>();
    public TreeNode increasingBST(TreeNode root) {
        //1.中序遍历该二叉树，并将该二叉树存到列表中
        Inorder_Traversal(root);
        //2.构建新的二叉树
        if(list==null||list.size()==0)
            return null;
        TreeNode res=new TreeNode(list.get(0));
        TreeNode tree=res;
        for(int i=1;i<list.size();i++)
        {
               res.right=new TreeNode(list.get(i));
               res=res.right;
        }
        return tree;
        
    }

    public void Inorder_Traversal(TreeNode root)
    {
        if(root==null)
            return ;
        Inorder_Traversal(root.left);
        list.add(root.val);
        Inorder_Traversal(root.right);
    }
}
```