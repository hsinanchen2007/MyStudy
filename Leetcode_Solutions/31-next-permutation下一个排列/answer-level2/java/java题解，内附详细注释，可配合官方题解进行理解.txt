class Solution {
    public void nextPermutation(int[] nums) {
        
        int i = nums.length-1;
        int j = nums.length-1;
        boolean judge = true;//判断数组是否为降序排列
        
        for(i=(nums.length-1);i>0;i--)//由后往前
        {
            if(nums[i]>nums[i-1])//后一个数大于前一个数，需要重新排序
            {
                judge=false;//数组不为降序排列
                
                for(j=(nums.length-1);j>=i;j--)
                {//在已查找完的数组段中找到刚好大于nums[i-1]的数，并与nums[i-1]交换位置
                    //nums[i-1]位置替换完成后，数组基本已成为（下一个！）更大的数
                    //此时只需对i至nums.length-1的数组段进行升序排列即可得到答案
                    if(nums[j]>nums[i-1])
                    {
                        int temp = nums[j];
                        nums[j]=nums[i-1];
                        nums[i-1]=temp;
                        break;//break，只需找到刚好大于的那一个数
                    }
                }
                
                for(int k=0;k<nums.length-i-1;k++)
                {//对i至nums.length-1的数组段进行冒泡排序
                    for(int l=i;l<nums.length-1-k;l++)
                    {
                        if(nums[l]>nums[l+1])
                        {
                            int temp = nums[l];
                            nums[l]=nums[l+1];
                            nums[l+1]=temp;
                        }
                    }
                }
                
                break;//只需找到一个大于的位置
            }
        }
        if(judge)//判断数组是否为降序排列，如果是，则进行升序操作
        {
            Arrays.sort(nums);
        }
    }
}