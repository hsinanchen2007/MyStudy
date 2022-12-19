**思路分析**：本题是[「力扣」第 15 题：三数之和](https://leetcode-cn.com/problems/3sum/) 的扩展问题。求最接近的三数之和，采用双指针对撞的思路。因为题目要求不能出现重复答案，因此首先要对数组排序。

编码的注意事项和细节已经体现在“参考代码”的注释中。

**参考代码**：

```Java []
import java.util.Arrays;

public class Solution {

    public int threeSumClosest(int[] nums, int target) {
        int len = nums.length;
        // 特判
        if (len < 3) {
            throw new IllegalArgumentException("参数错误");
        }
        // 初始化，因为找最小值，因此把初始值设置成实数的最大值
        int diff = Integer.MAX_VALUE;
        int res = nums[0] + nums[1] + nums[len - 1];
        // 排序是前提，很关键
        Arrays.sort(nums);
        // len-3 len-2 len-1

        for (int i = 0; i < len - 2; i++) {
            // 常见的剪枝操作，这里可以排除重复的情况
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 双指针：指针对撞
            int left = i + 1;
            int right = len - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // 不管是变小还是变大，尝试的作用是让 sum 与 target 更接近
                // 即 s 与 target 的绝对值之差越来越小
                if (sum > target) {
                    // 如果大了，尝试右边界收缩一格，让 target 变小
                    right--;
                } else if (sum < target) {
                    // 如果小了，尝试左边界收缩一格，让 target 变大
                    left++;
                } else {
                    // 如果已经等于 target 的话, 肯定是最接近的，根据题目要求，返回这三个数的和
                    assert sum == target;
                    return target;
                }

                if (Math.abs(sum - target) < diff) {
                    diff = Math.abs(sum - target);
                    res = sum;
                }
            }
        }
        return res;
    }
}
```
```Python []
from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        size = len(nums)
        # 特判
        if size < 3:
            return []
        # 初始化，因为找最小值，因此把初始值设置成实数的最大值
        diff = float('inf')

        # 排序是前提
        nums.sort()

        for i in range(size - 2):
            # 常见的剪枝操作
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            # 双指针：指针对撞
            left = i + 1
            right = size - 1
            while left < right:
                s = nums[i] + nums[left] + nums[right]

                if abs(s - target) < diff:
                    diff = abs(s - target)
                    res = s

                # 不管是变小还是变大，尝试的作用是让 s 与 target 更接近
                # 即 s 与 target 的绝对值之差越来越小
                if s > target:
                    # 如果大了，尝试右边界收缩一格，让 target 变小
                    right -= 1
                elif s < target:
                    # 如果小了，尝试左边界收缩一格，让 target 变大
                    left += 1
                else:
                    # 如果已经等于 target 的话, 肯定是最接近的，根据题目要求，返回这三个数的和
                    return target
        return res
```

**复杂度分析：**

+ 时间复杂度：$O(N^2)$，这里 $N$ 是数组的长度，排序的时间复杂度是 $O(N \log N)$，外层循环遍历 `i` ，内层循环指针对撞，时间复杂度是 $O(N^2)$。
+ 空间复杂度：$O(1)$，指针对撞和保存结果及中间变量的空间都为常数个。
