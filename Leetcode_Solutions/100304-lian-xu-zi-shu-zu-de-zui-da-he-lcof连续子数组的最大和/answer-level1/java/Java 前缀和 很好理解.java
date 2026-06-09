### 解题思路
                     i            j
    下标：      0  1  2   3  4  5  6  7  j
    原数组：    -2，1，-3，4，-1，2，1，-5，4
    下标：  0  1  2   3   4  5  6  7   8  9
    前缀和：0，-2，-1，-4，0，-1，1， 2，-3，1
  
    公式： sum[i,j]=prefixsum[j+1]-prefixsum[i]
          sum[2,6]=prefixsum[7]-prefixsum[2]=2-(-1)=3
    以j结尾的连续子数组和最大=prefixsum[j+1]-minsum(prefixsum[i],i->(0,j))



### 代码

```java
//前缀和
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums==null || nums.length==0){
            return 0;
        } 
        //求前缀和 nums={1,2,3} prefixsum={0,1,3,6}
        int [] prefixsum=new int[nums.length+1];
        prefixsum[0]=0;
        for(int i=0;i<nums.length;i++){
            prefixsum[i+1]=prefixsum[i]+nums[i];
        }
        //sum minsum 初始化为prefixsum[0]
        int max=Integer.MIN_VALUE,sum=0,minsum=0;
        //sum[i,j]=prefixsum[j+1]-prefixsum[i]
        //sum代表前i+1个数的和，max是全局最大值，sum-minsum代表以i结尾的最大连续子数组之和
        for(int i=0;i<nums.length;i++){
            sum=sum+nums[i];
            max=Math.max(max,sum-minsum);
            minsum=Math.min(minsum,sum);
        }        
        return max;       
    }
}
```