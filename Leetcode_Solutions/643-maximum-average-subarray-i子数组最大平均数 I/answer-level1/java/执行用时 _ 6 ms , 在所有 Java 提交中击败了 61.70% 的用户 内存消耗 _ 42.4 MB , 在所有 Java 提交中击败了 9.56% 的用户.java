### 解题思路
垃圾测试用例，给几千个数的数组，如果采用双遍历for循环会超时，只能利用上一次的和减去当前时刻第一个索引-1的值再加上当前时刻的索引加上k，这样就不会超时。

### 代码

```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        if(nums.length==k) {
            double sum = 0;
            for(int i:nums) {
                sum+=i;
            }
            return sum/k;
        }
        double SUM = 0.0;
        for(int i = 0;i<k;i++) {
            SUM = SUM+nums[i];
        }
        double MAX = SUM/k;
        for(int j = 1;j<nums.length-k+1;j++) {
            if(MAX<(SUM-nums[j-1]+nums[j+k-1])/k) {
                MAX = (SUM-nums[j-1]+nums[j+k-1])/k;
            }
            SUM = SUM-nums[j-1]+nums[j+k-1];
        }
        return MAX;
        

        
    }
}
```