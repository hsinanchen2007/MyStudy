### 解题思路
注释的是之前的想法，有点问题，子序和小于等于零时肯定不是最大和的情况，所以更新为下一个元素，再将当前子序和与之前最大子序和比较大小，取最大值

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0;
        int res = nums[0];
        for(int num : nums){
            if(sum > 0){
                sum += num;//num想当于nums[i]
            }else{
                sum = num;
            }
            res = Math.max(res, sum);
        }
        return res;
        // int maxSum = Integer.MIN_VALUE;
        // int[] maxSums = new int[nums.length];
        // for(int j = 0; j < nums.length; j++){//j轮循环
        //     maxSums[j] = nums[j];
        //     int sum = 0;
        //     for(int i = j + 1; i < nums.length; i++){
        //         sum = maxSums[j] + nums[i];
        //         if(sum > maxSums[j]){
        //             maxSums[j] = sum;
        //         }
        //     }
        //     if(maxSums[j] > maxSum){
        //         maxSum = maxSums[j];
        //     }
        // }
        // return maxSum;
    }
}
```