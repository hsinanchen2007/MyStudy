### 解题思路
见注释

### 代码

```java
class Solution {
    public int pivotIndex(int[] nums) {
        int totalSum = 0;
        int n = nums.length;
        // 如果数组长度为0，那么连元素都不存在，自然没有中心数组
        if (n == 0) {
            return -1;
        }
        // 计算数组总和
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        int traceSum = 0;
        // 开始累加，若在某个index处，累加之和 = 数组总合-num[index]-累加之和，则该index即为第一个中心索引，返回即可
        for (int i = 0; i < n; i++) {
            if (traceSum == totalSum - nums[i] - traceSum) {
                return i;
            }
            traceSum += nums[i];
        }
        return -1;
    }
}
```