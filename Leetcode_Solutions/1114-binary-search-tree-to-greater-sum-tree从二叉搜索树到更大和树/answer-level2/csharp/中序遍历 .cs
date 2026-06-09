二叉排序树中序遍历，先遍历右子树的书序就是从大到小的排序
因此遍历到当前节点的时候，正好访问过所有大于自己的节点
因此按照中序遍历过程遍历并累加，就得到每个节点的新值
```
public class Solution
{
    int counter = 0;
    void Helper(TreeNode n)
    {
        if (n == null) return;
        Helper(n.right);
        n.val = n.val + counter;
        counter = n.val;
        Helper(n.left);
    }

    public TreeNode BstToGst(TreeNode root)
    {
        Helper(root);
        return root;
    }
}
```
