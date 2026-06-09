首先明确一下思路：最大和路径一定可以看作是原树的某一个子树subT，假设它的根为root,那么它一定符合条件：root的左子女到subT的左侧叶子节点的路径和是原树的中最大的，如果这个最大值小于00，我们就去掉这个左边的路径。右边路径同理。
我们用一个含两个元素的pair数组，分别记录当前节点的左右侧最大路径和。每计算完一个节点的pair数组，就尝试以它为根计算路径和，更新结果sum。并将pair返回，给父节点使用。
那么应该如何使用左右子女提供的pair呢？对于父节点f的左子女left,父节点的左侧最大路径应该是左子女返回的pair最大者加上left.val。接下来就是更新以f为根的sum了。
```
class Solution {
    int maxSum=0;
//    TreeNode tureRoot;
    public int[] rlSum(TreeNode root){
        //root!=NULL
        int[]pair=new int[]{root.val,root.val};
        int sum=root.val;//以root为根的最大路径
        if(root.right!=null)
        {
            int[]right=rlSum(root.right);
            int bigger=Math.max(right[0],right[1]);
            if(bigger>0)
                sum+=bigger;
            pair[1]=Math.max(pair[1],pair[1]+bigger);
            if(pair[1]<0){
                pair[1]=0;
            }
        }
        if(root.left!=null){
            int[]left=rlSum(root.left);
            int bigger=Math.max(left[0],left[1]);
            if(bigger>0)
                sum+=bigger;
            pair[0]=Math.max(pair[0],pair[0]+bigger);
            if(pair[0]<0){
                pair[0]=0;
            }
        }
        maxSum=Math.max(sum,maxSum);
        return pair;
    }
    public int maxPathSum(TreeNode root) {
        if(root!=null){
//            tureRoot=root;
            maxSum=root.val;
            rlSum(root);
        }
        return maxSum;
    }
}

```