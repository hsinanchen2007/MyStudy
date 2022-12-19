### 解题思路

重点是需要知道动态规划数组的含义：
dp_max[i] 指的是以第 i 个数结尾的乘积最大的连续子序列
dp_min[i] 指的是以第 i 个数结尾的乘积最小的连续子序列

然后当遇到负数的时候需要将dpmax[i-1] 和 dpmin[i-1]的值交换进行计算。

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        if(nums.length == 0) 
            return 0;
        
        int[] dp_max = new int[nums.length+1];
        int[] dp_min = new int[nums.length+1];

        int max = Integer.MIN_VALUE;
        // 由于存在负数，所以需要维护两个数组
        // dp_max[i] 指的是以第 i 个数结尾的 乘积最大 的连续子序列
        // dp_min[i] 指的是以第 i 个数结尾的 乘积最小 的连续子序列
        
        dp_max[0] = 1;
        dp_min[0] = 1;
        
        for (int i = 1;i <= nums.length;i++){
            if(nums[i-1] < 0){
                int temp = dp_min[i-1];
                dp_min[i-1] = dp_max[i-1];
                dp_max[i-1] = temp;
            }
        
            dp_min[i] = Math.min(nums[i-1],dp_min[i-1]*nums[i-1]);
            dp_max[i] = Math.max(nums[i-1],dp_max[i-1]*nums[i-1]);
        
            max = Math.max(max,dp_max[i]);
        }
        return max;
    }
}
```