
总结一下写二分查找法的思路：

+ `while(left < right)` 在退出循环的时候，一定有 `left == right` 成立，因此，在循环中，不断排除不是目标元素的区间，以确定下一轮搜索的区间，进而确定边界如何设置，在退出循环的时候，根据情况，需要单独做一次判断；
+ 在循环体里，对 `nums[mid]` 与 `target` 的大小关系的判断，可以二分，也可以三分，本题采用三分去判断，只是为了演示怎么设置边界：先得到目标元素可能在哪个区间里，然后再设置边界，这样不容易出错，建议写成注释；可以二分的好处是只要一边判断是正确的，另一边就是其反面，考虑的内容会少一些；
+ 看到边界是 `left = mid` 的时候，取中间数的计算表达式应该上取整，即在括号里加 `1`；
+ 编码时应该先写主干逻辑，然后分支逻辑作为私有函数。

**参考代码 1**：

```Java []
public class Solution {

    public int search(int[] nums, int target) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }

        int firstPosition = findFirstPosition(nums, target);
        if (firstPosition == -1) {
            return 0;
        }

        int lastPosition = findLastPosition(nums, target);
        return lastPosition - firstPosition + 1;
    }

    private int findLastPosition(int[] nums, int target) {
        int len = nums.length;
        int left = 0;
        int right = len - 1;
        while (left < right) {

            // 注意，以下 nums[mid] < target 以及 nums[mid] == target 的情况可以合并
            // 边界是 left = mid ，取中间数的时候必须 + 1
            int mid = (left + right + 1) >>> 1;

            if (nums[mid] < target) {
                // mid 以及 mid 左边都不是，下一轮搜索区间在 [mid + 1, right]
                left = mid + 1;
            } else if (nums[mid] == target) {
                // mid 可能是，mid 左边一定不是，下一轮搜索区间在 [mid, right]
                left = mid;
            } else {
                // 此时 nums[mid] > target
                // mid 以及 mid 右边都不是，下一轮搜索区间在 [left, mid - 1]
                right = mid - 1;
            }
        }
        return left;
    }

    private int findFirstPosition(int[] nums, int target) {
        int len = nums.length;
        int left = 0;
        int right = len - 1;
        while (left < right) {
            int mid = (left + right) >>> 1;

            if (nums[mid] < target) {
                // mid 以及 mid 左边都不是，下一轮搜索区间在 [mid + 1, right]
                left = mid + 1;
            } else if (nums[mid] == target) {
                // mid 可能是，mid 右边一定不是，下一轮搜索区间在 [left, mid]
                right = mid;
            } else {
                // 此时 nums[mid] > target
                // mid 以及 mid 右边都不是，下一轮搜索区间在 [left, mid - 1]
                right = mid - 1;
            }
        }

        if (nums[left] == target) {
            return left;
        }
        return -1;
    }
}
```

**复杂度分析**：

+ 时间复杂度：$O(\log N)$，这里 $N$ 为数组的长度；
+ 空间复杂度：$O(1)$，记录第一次出现的位置和最后一次出现的位置还有临时变量的位置，只有常数个。
