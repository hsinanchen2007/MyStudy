### 解题思路
1 排序
2 遍历
2.1 统计0数量
2.2 比较相邻，不符合跳出
2.3 判断跨度大于1，并扣减zero数量

### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        // 1 先对数组进行排序
        Arrays.sort(nums);
        // 遍历
        int zeroCounter = 0;
        for (int i = 0; i < 4; i++) {
            // 2 统计0数量
            if (nums[i] == 0) {
                zeroCounter++;
                continue;
            }
            // 3 比较相邻，如果相等就不符合
            if (nums[i] == nums[i + 1]) {
                return false;
            }
            // 4 对前后差值差值大于1的进行扣减zero
            if (nums[i + 1] - nums[i] > 1) {
                zeroCounter -= nums[i + 1] - nums[i] - 1;
            }
        }
        return zeroCounter >= 0;
    }
}
```