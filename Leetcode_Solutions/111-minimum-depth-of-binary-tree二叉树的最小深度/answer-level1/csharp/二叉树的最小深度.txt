**思路1：** 递归，详情都在代码里。
```
 public int MinDepth(TreeNode root)
        {
            //递归终止情况1
            if (root == null)
            {
                return 0;
            }
            //递归终止情况2
            if (root.left == null && root.right == null)
            {
                return 1;
            }

            if (root.left == null)
            {
                return MinDepth(root.right) + 1;
            }
            else if (root.right == null)
            {
                return MinDepth(root.left) + 1;
            }
            return Math.Min(MinDepth(root.left), MinDepth(root.right)) + 1;
        }
```
