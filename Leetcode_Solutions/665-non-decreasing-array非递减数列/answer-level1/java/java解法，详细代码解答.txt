```java
class Solution {
    public boolean checkPossibility(int[] nums) {
       //换一个思路，不拷贝数组然后排序了,具体分为更改第i个值，还是第i+1个值
        int counts=1;
        for(int i=0;i<nums.length-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                //第一个值必须变更改的为i，举例：423
                if(i==0)
                {
                    counts--;
                    continue;
                }
                //更改i，举例1546的5，其实就是i-1,i,i+1可以成为非递减数列
                if(i-1>=0&&nums[i+1]>=nums[i-1])
                {
                    counts--;
                }
                //更改i+1，举例1304，此时i为3，要更改i+1(0)，假如将3改为-1，1和-1还是递减
                //此时就是 i-1，i,i+1无法组成非递减数列，但i-1, i,i+2可以组成非递减数列，这样就让
                // i-1,i,i+1,i+2变成非递减数列。这里的第二种情况就是i+1是数组的最后一个元素了，而i以及i之前的数（i-1，i-2，i-3）都已经按照非递减数列排列好了，那么我们就更改i+1就好，让他比i大即可
                else if((i-1>=0&&i+2<nums.length&&nums[i+2]>=nums[i]&&nums[i+2]>=nums[i-1])||(i + 1 == nums.length-1))
                    counts--;
                else
                    return false;
            }
            if(counts<0)
                    return false;
        }
        return true;
    }
}
```
