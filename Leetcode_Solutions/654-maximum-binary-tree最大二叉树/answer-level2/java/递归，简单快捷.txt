每次在指定范围（left，right）内找最大值的index，然后new一个TreeNode后递归让它的左孩子为（left,inde-1）内的最大值，右孩子为（index+1，right）内的最大值，当left>right时返回null

java代码:
```
class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return createMaxTree(nums,0,nums.length-1);
    }
    private TreeNode createMaxTree(int [] nums,int left,int right)
    {
        if(left>right)
            return null;
        int index=maxIndex(nums,left,right);
        TreeNode root=new TreeNode(nums[index]);
        root.left=createMaxTree(nums,left,index-1);
        root.right=createMaxTree(nums,index+1,right);
        return root;
    }
    private int maxIndex(int [] nums,int low,int high)
    {
        int maxIndex=low;
        for(int i=low+1;i<=high;i++)
            if(nums[i]>nums[maxIndex])
            {
                maxIndex=i;
            }
        return maxIndex;
    }
}
```
