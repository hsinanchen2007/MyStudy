class Solution {
    public int singleNumber(int[] nums) {
        
        Arrays.sort(nums);//对数组进行排序
        
        int i=0;
        int n = nums.length;
        int result = nums[0];//只有一个数的情况
        
        while(i<n-1)//对排序后的数组进行两两对比处理
        {
            if(nums[i]!=nums[i+1])
            {//找到不一样的数
                result=nums[i];
                return result;
            }
            i=i+2;//+2处理
        }
        
        result=nums[n-1];//while循环结束后未结束函数，说明出现一次的元素在最后一位，赋值即可
        
        return result;
    }
}