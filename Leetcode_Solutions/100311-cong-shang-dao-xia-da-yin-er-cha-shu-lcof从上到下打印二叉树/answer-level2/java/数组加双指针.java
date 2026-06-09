```
public int[] levelOrder(TreeNode root)
    {
        if (root == null)
        {
            return new int[0];
        }
        TreeNode[] qq = new TreeNode[2000];
        int[] l = new int[2000];
//一个指针读现有的，一个指针写以后的，顺便把结果写上
        int now = 0;
        int next = 0;
        qq[0] = root;
        while (now <= next)
        {
            l[now] = qq[now].val;
            if (qq[now].left != null)
            {
                qq[++next] = qq[now].left;
            }
            if (qq[now].right != null)
            {
                qq[++next] = qq[now].right;
            }
            now++;
        }
        return Arrays.copyOfRange(l,0,now);

    }
```
