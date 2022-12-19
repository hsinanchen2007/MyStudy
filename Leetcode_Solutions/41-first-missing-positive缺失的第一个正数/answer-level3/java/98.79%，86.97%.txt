### 解题思路
思路一:
通过数组记录大小在 1 到 len 的数字（目标值可能出现的范围）是否出现过，未出现的最小值即为目标值。
遍历两次即可。

### 代码

```java
class Solution {
    public static int firstMissingPositive(int[] nums) {
        int len = nums.length;
        int[] hasAppear = new int[len];
        for (int n : nums) {
            if (n > 0 && n < len + 1) { // 将 1 到 len 之间出现过的数字存入数组，结果必然是其中之一
                hasAppear[n - 1] = 1;
            }
        }
        for (int i = 0; i < len; i++) {
            if (hasAppear[i] == 0) { // 没有出现过的最小值即为目标值
                return i + 1;
            }
        }
        return len + 1;
    }
}
```

### 解题思路
思路二：
记录每个数字的前后数字，这些数字里没有出现在输入数组中的最小值即为目标值。

### 代码
```java
public static int firstMissingPositive(int[] nums) {
        // 第一次遍历，将无用数据处理为0，同时记录出现的最小正数
        int min = Integer.MAX_VALUE;
        Set<Integer> hasAppear = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 1 || nums[i] > nums.length) { // 小于1以及大于数组长度的数都是无效数
                nums[i] = 0;
            } else {
                min = Integer.min(nums[i], min);
                hasAppear.add(nums[i]);
            }
        }
        if (min != 1) {
            return 1;
        }
        // 第二次遍历
        int result = Integer.MAX_VALUE;
        for (int n : nums) {
            if (n > 0) {
                if (n - 1 > 0 && !hasAppear.contains(n - 1)) {
                    result = Math.min(result, n - 1);
                }
                if (!hasAppear.contains(n + 1)) {
                    result = Math.min(result, n + 1);
                }

            }
        }
        return result;
    }
```