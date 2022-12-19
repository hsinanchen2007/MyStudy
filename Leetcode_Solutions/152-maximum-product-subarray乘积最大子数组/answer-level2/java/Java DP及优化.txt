考虑到负负得正的情况，需要同时保留最大值和最小值，每次对比“最小值\*当前值”和“最大值\*当前值”的大小，再做判断。
DP方程：
最大值：
dpMax[i] = Math.max(nums[i], Math.max(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i]))
最小值：
dpMin[i] = Math.min(nums[i], Math.min(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i]))

```java
class Solution {
    public int maxProduct(int[] nums) {
        int[] dpMax = new int[nums.length], dpMin = new int[nums.length];
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        int max = nums[0], tmpMin, tmpMax;
        for (int i = 1; i < nums.length; i++) {
            tmpMin = dpMin[i - 1] * nums[i];
            tmpMax = dpMax[i - 1] * nums[i];
            dpMax[i] = Math.max(nums[i], Math.max(tmpMin, tmpMax));
            dpMin[i] = Math.min(nums[i], Math.min(tmpMin, tmpMax));
            max = Math.max(max, dpMax[i]);
        }
        return max;
    }
}
```

简化，不需要定义数组，只需要定义最大值最小值两个变量即可：
```java
class Solution {
    public int maxProduct(int[] nums) {
        int max = nums[0], curMin = nums[0], curMax = nums[0], tmpMin, tmpMax;
        for (int i = 1; i < nums.length; i++) {
            tmpMin = curMin * nums[i];
            tmpMax = curMax * nums[i];
            curMin = Math.min(nums[i], Math.min(tmpMin, tmpMax));
            curMax = Math.max(nums[i], Math.max(tmpMin, tmpMax));
            max = Math.max(max, curMax);
        }
        return max;
    }
}
```

简化2，通过判断当前值的正负来进行最大值最小值交换：
```java
class Solution {
    public int maxProduct(int[] nums) {
        int max = nums[0], curMin = nums[0], curMax = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < 0) {
                int tmp = curMax;
                curMax = curMin;
                curMin = tmp;
            }
            curMin = Math.min(nums[i], curMin * nums[i]);
            curMax = Math.max(nums[i], curMax * nums[i]);
            max = Math.max(max, curMax);
        }
        return max;
    }
}
```
