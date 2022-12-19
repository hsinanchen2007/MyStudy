```
class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer,Integer> hm=new HashMap<>();
        for(int i:nums)
        {
            hm.put(i,hm.getOrDefault(i,0)+1);
        }
        int max=0;
        for(int i:hm.keySet())
        {
            int y=hm.get(i);
            if(y>=max)
               max=y;
        }                //求出最大频数
        int min=nums.length;
        for(int i:hm.keySet())
        {
            if(hm.get(i)==max)   //一个频数为max的元素
            {
                int low=0;
                int high=nums.length-1;
                while(nums[low]!=i)
                    low++;        //从左边算起,第一个出现的下标
                while(nums[high]!=i)
                    high--;       //从右边算起,第一个出现的下标
                if(high-low>=0&&high-low+1<min) 
                      min=high-low+1;   //和min比较
            }
        }
        return min;
    }
}

```
执行用时 :49 ms, 在所有 Java 提交中击败了32.50% 的用户 
内存消耗 :46.5 MB, 在所有 Java 提交中击败了5.03%的用户..
时间是有点长了...希望各位帮助优化一下...
