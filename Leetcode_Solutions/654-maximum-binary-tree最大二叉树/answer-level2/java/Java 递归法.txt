***我的[leetcode解题集](https://github.com/JuiceZhou/Leetcode/blob/master/java/tree/%24654_MaximumBinaryTree.java)，持续更新。***

本题采用递归法，每一次递归的根节点为当前数组中的最大值，然后递归构建其左子树，数组范围为[start,maxIndex-1]，递归构建右子树，数组范围为[maxIndex+1,end]，这里的递归索引均取闭区间，方便计算。

```
 public TreeNode constructMaximumBinaryTree(int[] nums) {
    if (nums.length == 0) return null;
        return helper(nums, 0, nums.length - 1);
}

private TreeNode helper(int[] nums, int lo, int hi) {
    if (lo > hi) return null;
    //找到当前数组的最大值索引
    int index = getMax(nums,lo,hi);
    //根元素
    TreeNode root = new TreeNode(nums[index]);
    //递归
    root.left = helper(nums,lo,index-1);
    root.right = helper(nums,index+1,hi);
    return root;
}

private int getMax(int[] nums, int lo, int hi) {
    int max = Integer.MIN_VALUE,maxIndex = -1;
    for(int i = lo;i <= hi;i++){
        if(max < nums[i]){
            max = nums[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}
```
