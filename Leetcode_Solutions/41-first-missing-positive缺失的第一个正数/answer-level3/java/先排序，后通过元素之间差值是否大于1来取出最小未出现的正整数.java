先将数组排序，然后判断两个数组元素间的差是否大于1，如果大于1，直接返回较小元素的值+1即可。

代码如下：

import java.util.Arrays;

public class Solution {

    public static void main(String[] args) {

        Solution test=new Solution();
        int[] input={-1,4,2,1,9,10};
        int result = test.firstMissingPositive(input);
        System.out.println(result);

    }


    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int firstBigerThanZeroIndex=-1;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]<=0)
            {
                continue;
            }
            firstBigerThanZeroIndex=i;
            break;
        }
        int result=0;
        if(firstBigerThanZeroIndex==-1)
        {
            result=1;
        }
        else if(nums[firstBigerThanZeroIndex]==1)
        {
            boolean findResult=false;
            for(int i=firstBigerThanZeroIndex+1;i<nums.length;i++)
            {
                if(nums[i]-nums[i-1]>1)
                {
                    result  =nums[i-1]+1;
                    findResult=true;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if(!findResult)
            {
                result=nums[nums.length-1]+1;
            }
        }
        else
        {
            result=1;
        }

        return result;
    }

}
