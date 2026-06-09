这题跟前面的求二叉树最大深度是相同的思路，只是在递归比较左右子树深度的时候去二者的最小值即可，代码如下：
```
public int MinDepth(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }
        if (root.left == null && root.right == null)
        {
            return 1;
        }
        else if (root.left != null && root.right == null)
        {
            return MinDepth(root.left) + 1;
        }
        else if (root.right != null && root.left == null)
        {
            return MinDepth(root.right) + 1;
        }
        else
        {
            return Math.Min(MinDepth(root.left), MinDepth(root.right)) + 1;
        }
    }
```
