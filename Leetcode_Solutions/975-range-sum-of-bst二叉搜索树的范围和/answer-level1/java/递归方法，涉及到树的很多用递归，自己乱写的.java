

用时1 msjava击败了97.01%
内存45.1 MB击败了91.06%
//判断是否是空若空则结束返回res值，若不为空的话判断该点，
//值符合要求要求则加得结果
//接下来同样方法遍历左子树，同理遍历右
//别忘了最开始给基础res=0；
    public int rangeSumBST(TreeNode root, int L, int R) 
    {
        return qiuhe(root,L,R,0);
    }
    public static int qiuhe(TreeNode root, int L, int R,int res)
    {
        if(root!=null)
            res = (root.val>=Math.min(L,R)&&root.val<=Math.max(L,R))? res+root.val:res;
        else
            return res;
        res=qiuhe(root.left,L,R,res);
        res=qiuhe(root.right, L,R,res);
        return res;   
    }

