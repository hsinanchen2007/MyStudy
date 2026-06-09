遍历树的每个节点，对于每个节点求其左子树和右子树深度之和，返回其中的最大值
```
public int diameterOfBinaryTree(TreeNode root) {
        if (root==null)
            return 0;
        int len1=0,len2=0,left=0,right=0;
        len1=getRootdeep(root.left);
        len2=getRootdeep(root.right);
        if (root.left!=null)
            left=diameterOfBinaryTree(root.left);
        if (root.right!=null)
            right=diameterOfBinaryTree(root.right);
        return max(len1+len2,left,right);
    }
    public int getRootdeep(TreeNode root)
    {
        if (root==null)
            return 0;
        return Math.max(getRootdeep(root.left),getRootdeep(root.right))+1;
    }
    public int max(int a,int b,int c)
    {
        int d=Math.max(a,b);
        return Math.max(d,c);
    }
```