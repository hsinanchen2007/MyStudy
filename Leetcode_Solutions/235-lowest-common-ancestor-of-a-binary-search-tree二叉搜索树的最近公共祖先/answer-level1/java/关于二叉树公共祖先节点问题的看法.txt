
```
class Solution {
    
    public int d;
    //public int val;
    public TreeNode outcome;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        d = Integer.MIN_VALUE;
        //val = root.val;
        recurse(root, p.val, q.val, 0);
        return outcome;
    }

    public int recurse(TreeNode t, int pval,  int qval, int depth)
    {
        if(t == null)
            return 0;
        
        int l = recurse(t.left, pval, qval, depth+1);
        int r = recurse(t.right, pval, qval, depth+1);
        int res = 0;
        if(t.val == qval || t.val == pval)
        {
            res = l+r+1;
        }
        else
        {
            res = l+r;
        }

        if(res == 2 && depth > d)
        {
           // val = t.val;
            d =depth;
            outcome = t;
        }
        return res;
    }

}
```
个人认为主要问题有如下两点：  
1. 如何判定某个节点是p、q的祖先节点；
2. 保证最后的祖先节点是满足条件的节点中深度最大的；

对问题1，使用递归方法解决，思路为：递归过程中记录p、q节点出现次数，记为res，对当前节点，计算res，若res==0，则表明在当前的 左右子树+当前节点 中p、q节点均未出现。

对问题2，当且仅当res==2时，更新outcome，记录下深度最大的公共祖先节点。

简而言之，求取当前节点下**p或q值出现的次数**。