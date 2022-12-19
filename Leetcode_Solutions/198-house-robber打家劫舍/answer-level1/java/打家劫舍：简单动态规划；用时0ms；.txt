### 解题思路
根据题意，相邻的房间的金额不可同时取出，计算进入每个房间时可偷窃到最高金额，故i=0时为第一个房间的金额数，i=1时为第二个房间的金额数，i=2时最大金额只能为当前房间的金额数加上第一房间的金额数，故当i>=3时,应取到达前前两个房间时可窃取的金额最大值，状态转移方程为：value[i] = Math.max(value[i - 2], value[i - 3]) + nums[i]; 定义max来记录最大的value[i]的值。

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        int length = nums.length;
        int[] value = new int[length];
        int max = 0;
        for (int i = 0; i < length; i++) {
            if(i == 0 || i == 1) {
                value[i] = nums[i];
            } else if(i == 2) {
                value[i] = nums[i] + nums[i-2];
            } else {
                value[i] = Math.max(value[i - 2], value[i - 3]) + nums[i];
            }
            max = max < value[i] ? value[i] : max;
        }
        return max;
    }
}
```