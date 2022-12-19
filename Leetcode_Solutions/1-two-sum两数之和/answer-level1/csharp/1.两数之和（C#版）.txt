暴力法：简单明了
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        for(int i=0;i<nums.Length;i++)
        {
            for(int j = 0;j<nums.Length;j++)
            {
                if(i!=j)
                {
                    if((nums[i]+nums[j])==target)
                    {
                        return new int[]{i, j};
                    }
                }
            }
        }
        return default;
    }
}