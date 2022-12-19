主要思路，利用下标范围刚好是0~n之间，然后数字也是1~n之间
把对应元素放到数值对应的下标那边去，如果有一次放的时候，发现对应下标下已经有这个数值，那么就是重复了。
class Solution {
    public int findDuplicate(int[] nums) {
        int len=nums.length;
        //1~n的数值，分别放到n对应的下标
        int res=0;
        int i=0;
        while(i<len){
            if(nums[i]!=i){ //数值跟下标不对应
                if(nums[nums[i]]==nums[i]){ //对应下标的数值是更新现在一样的
                    res=nums[i];
                    break;
                }
                //交换:nums[i],i下标
                int tmp=nums[nums[i]];
                nums[nums[i]]=nums[i];
                nums[i]=tmp;
            }
            if(nums[i]==i)
                i++;
        }
        return res;
    }
}