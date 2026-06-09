```
/**
    1、排序
    2、循环，确认第一个值，第二个值left最小值、第三个值right最大值 指针
        循环第一个值后（i > 0）由于相同值时会导致重复集合，需排除（i 第一次出现时已取值了）
        while (left < right) 注意边界值相同情况
 */
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        List<IList<int>> list = new List<IList<int>>();
        int length = nums.Length;
        if (length <= 2) {
            return list;
        }
        nums = Sort(nums);
        List<int> subList = new List<int>();
        int ans = 0, current = int.MinValue, leftValue = int.MinValue, rightValue = int.MaxValue;
        for (int i = 0; i < length - 2; i++) {
            // 最小值已经大于0
            if (nums[i] > 0) {
                break;
            }
            // 去除重复集合（List<int>），最左边（i-1）已包含集合，下一个相同值时去除
            if ((i > 0) && (nums[i] == nums[i - 1])) {
                continue;
            }
            int left = i + 1, right = length - 1;
            current = nums[i];
            while (left < right) {     
                leftValue = nums[left];
                rightValue = nums[right];
                ans = current + leftValue + rightValue;
                if (ans == 0) {
                    // 3者和为 0, 插入 list 数据
                    subList = new List<int>();
                    subList.Add(current);
                    subList.Add(leftValue);
                    subList.Add(rightValue);
                    list.Add(subList);
                    // right--, left++ 去除重复值
                    while (rightValue == nums[--right] && left < right) {
                    }
                    while (leftValue == nums[++left] && left < right) {
                    }
                } else if (ans > 0) {
                    // 和大于 0，多了最大值--，right-- 去除重复值
                    while (rightValue == nums[--right] && left < right) {
                    }
                } else {
                    // 和小于 0，少了最小值++，left-- 去除重复值
                    while (leftValue == nums[++left] && left < right) { 
                    }
                }
            }
        }
        return list;
    }

    // 快速排序
    public int[] Sort(int[] nums) {
        int length = nums.Length;
        RecursiveSort(nums, 0, length - 1);
        return nums;
    }
    // 递归排序
    public void RecursiveSort(int[] nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int index = GetIndex(nums, low, high);
        RecursiveSort(nums, low, index - 1);
        RecursiveSort(nums, index + 1, high);
    }
    // 快排找到 index
    public int GetIndex(int[] nums, int low, int high) {
        int target = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= target) {
                high--;
            }
            nums[low] = nums[high];
            while (low < high && nums[low] <= target) {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = target;
        return low;
    }
}
// Accepted
//     313/313 cases passed (400 ms)
//     Your runtime beats 79.28 % of csharp submissions
//     Your memory usage beats 14.81 % of csharp submissions (34.6 MB)
```
