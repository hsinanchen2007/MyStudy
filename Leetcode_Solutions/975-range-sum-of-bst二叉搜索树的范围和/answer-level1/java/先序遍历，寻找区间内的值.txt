class Solution 
{
    
    public int rangeSumBST(TreeNode root, int L, int R) 
    {
        int sum=0;
        if(root==null)
            return 0;
        if(root.val>=L&&root.val<=R)
            sum+=root.val;

        sum+=rangeSumBST(root.right,L,R);
        sum+=rangeSumBST(root.left,L,R);
        return sum;
    }

   
}
正常先序遍历即可。

