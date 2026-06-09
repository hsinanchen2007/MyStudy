### 解题思路
滑动窗口思路：
1. 窗口内数的个数小于 K 时，往窗口中添加数
2. 窗口内个数等于 K 时，计算此时窗口内所有数和的平均值

### 代码

```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        if (k > nums.length) {
            return 0.0;
        }
        int left = 0, right = 0;
        double sum = 0;
        double average = Integer.MIN_VALUE;
        while (right < nums.length) {
            // 窗口内数的个数小于 K
            if (right - left < k) {
                sum += nums[right];
                right++;
                continue;
            }
            // 窗口内个数 == K，计算平均值
            average = Math.max(average, sum / k);
            sum -= nums[left++];
            sum += nums[right++];
        }
        // 注意: 这里计算最后一个窗口的平均值
        average = Math.max(average, sum/k);
        return average;
    }
}
```