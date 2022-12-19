### 解题思路
此题虽然标为简单 但其实不看答案基本想不出来
属于基础题
贪心、动态规划 时间复杂度N 都需要掌握
分治法 时间复杂度NLogN 有点绕 看懂就忘记 也需要掌握

### 代码

```java
import java.lang.Math;
class Solution {
    public int maxSubArray(int[] nums) {
        /*
        //贪心算法 时间复杂度 N
        int len = nums.length;

        //最大值
        int sum = nums[0];//当前位置之前的最大值

        int maxSum = nums[0];

        for (int i = 1; i < len; i++) {
            sum +=nums[i]; 
            sum = Math.max(sum, nums[i]);
            maxSum = Math.max(maxSum, sum);
        }

        return maxSum;
        */

        //动态规划算法 时间复杂度 N
        int len = nums.length;

        int maxSum = nums[0];//最大值

        for (int i = 1; i < len; i++) {
            if (nums[i-1] > 0) nums[i] += nums[i-1];
            maxSum = Math.max(maxSum, nums[i]);
        }
        
        return maxSum;
        //分治法 nlogn todo---
    }
}
```