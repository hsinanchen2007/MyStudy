class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count=0;//记录每次的1的个数
        int max=0;//记录
        int result=0;
        for (int i=0;i<nums.length;i++){
            if(nums[i]==1)
                ++count;
            else{
                if(count>max)
                    max=count;
                count=0;
            }
        }
         //[1]这个情况特殊
        return result=(max>count)?max:count;//三元组，？前边的公式如果成立则返回?后第一个，不成立返回第二个
        
    }
}