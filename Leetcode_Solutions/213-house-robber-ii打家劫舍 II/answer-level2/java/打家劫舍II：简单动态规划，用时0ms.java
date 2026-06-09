### 解题思路
根据题意，相邻的房间的金额不能同时取出，并且房间为环形循环，定义一个数组value来存放每个房间可以窃取到的最大金额数，因房间为环形循环，故取了第一个房间的金额，则最后一个房间的金额不能取。则可以统计从第一个房间开始，到倒数第二个房间时可窃取的最大金额数，和统计从第二个房间开始到最后一个房间可窃取的最大金额数，定义max来存放窃取的最大金额数。状态转移方程为： value[i] = Math.max(value[i - 2], value[i - 3]) + nums[i];

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        int length = nums.length;
        int max = 0;
        if(length == 1) max = nums[0];
        max = common(0, length -1, nums, max);
        max = common(1, length, nums, max);
        return max;
    }

    public int common(int  r, int l, int[] nums, int max) {
        int length = nums.length;
        int[] value = new int[length];
        for (int i = r; i < l; i++) {
            if(i == r || i == r+1) {
                value[i] = nums[i];
            } else if(i == r+2) {
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