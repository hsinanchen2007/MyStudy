### 方法一：暴力法

遍历一次数组，选出最小值。这个方法叫“假设修正法”。

### 方法二：二分法

二分法也可以解决这个问题，因为“旋转排序数组”，几乎有序的数组，也可以通过比较特定位置的元素的值的判断达到“减治”的效果（逐渐缩小搜索区间）。

很自然地，我们会看中间数（位于待搜索区间中间位置的元素，由于不是有序数组，因此不能称之为中位数）。

另外，待搜索区间头和尾的元素是位置特殊的元素。有两个比较自然的思路是：

+ 思路 1：看看当前搜索区间的左边界和“中间数”（注意这里不是中位数），是不是可以缩小搜索区间的范围；

+ 思路 2：看看当前搜索区间的右边界和“中间数”（注意这里不是中位数），是不是可以缩小搜索区间的范围；

要想清楚这个问题，我们不妨举几个例子。

+ 针对思路 1：

例 1：`[1, 2, 3, 4, 5]`

例 2：`[2, 3, 4, 5, 1]`

这两个例子的“中间数”都比左边界大，但是“旋转排序数组”的最小值一个在“中间数”的左边，一个在“中间数”的右边，因此思路 1 不可行。

+ 针对思路 2，依然写两个例子，这两个例子分别是“中间数比右边界大”和“中间数比右边界小”，看看能不能推导出一般化的结论。

例 3：`[7, 8, 9, 10, 11, 12, 1, 2, 3]`

“中间数” 11 比右边界 3 大，因此中间数左边的数（包括中间数）都不是“旋转排序数组”的最小值，因此，下一轮搜索的区间是 `[mid + 1, right]`，将下一轮搜索的左边界设置成中间数位置 + 1，即 `left = mid + 1`。

例 4：`[7, 8, 1, 2, 3]`

“中间数” 1 比右边界 3 小，说明，中间数到右边界是递增的，那么中间数右边的（不包括中间数）一定不是“旋转排序数组”的最小值，可以把它们排除，但中间数有可能是整个数组中的最小值，就如本例，因此，在下一轮搜索区间是 `[left, mid]`，于是把右边界设置为 `right = mid`。

从例 3 和例 4 可以看出，不论中间数比右边界大，还是中间数比右边界小，我们都可以排除掉将近一半的元素，把原始问题转换成一个规模更小的子问题，这正是“减而治之”思想的体现，因此思路 2 可行。

二分查找法的写法，我归纳在了「力扣」第 35 题：“搜索插入位置”的题解[《用“排除法”（减治思想）写二分查找问题、与其它二分查找模板的比较》](https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)，希望能对大家有所帮助。

**参考代码 1**：

```Java []
public class Solution {

    public int findMin(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            throw new IllegalArgumentException("数组为空，无最小元素");
        }
        int left = 0;
        int right = len - 1;
        while (left < right) {
            // int mid = left + (right - left) / 2;
            int mid = (left + right) >>> 1;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // 因为题目中说：你可以假设数组中不存在重复元素。
                // 此时一定有 nums[mid] < nums[right]
                right = mid;
            }
        }
        // 一定存在最小元素，因此无需再做判断
        return nums[left];
    }
}
```
```Python []
from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 0:
            raise Exception('程序出错')
        if size == 1:
            return nums[0]
        left = 0
        right = size - 1
        while left < right:
            # mid = left + (right - left) // 2
            mid = (left + right) >> 1
            # [7, 8, 1, 2, 3, 4, 5, 6]
            if nums[mid] > nums[right]:
                # [3, 4, 5, 6, 7, 8, 1, 2]
                # 此时 mid 肯定不是最小元素
                left = mid + 1
            else:
                # mid 有可能是最小元素，所以，不能排除它
                assert nums[mid] < nums[right]
                right = mid
        # 一定存在最小元素，因此无需再做判断
        return nums[left]
```

### 方法三：分治法

有了二分法的思路，分治法其实就不难了。我个人觉得分治法和二分法没有什么本质差别，只是写法上不一样而已。

二分思想的本质就是“减治”，“减治”是“分治”的特例，“减治”可以办到的事情，何必用“分治”呢？分治法同样适用于 LeetCode 第 154 题。

**参考代码 2**：

```Java []
public class Solution {

    public int findMin(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            throw new IllegalArgumentException("数组为空");
        }
        return findMin(nums, 0, len - 1);
    }

    private int findMin(int[] nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        if (left + 1 == right) {
            return Math.min(nums[left], nums[right]);
        }
        int mid = (left + right) >>> 1;

        if (nums[mid] < nums[right]) {
            // 右边是顺序数组，[mid + 1 , right] 这个区间里的元素可以不看
            return Math.min(findMin(nums, left, mid - 1), nums[mid]);
        } else {
            // nums[mid] > nums[right]
            // 左边是顺序数组，[left + 1, mid] 这个区间里的元素可以不看
            return Math.min(nums[left], findMin(nums, mid + 1, right));
        }
    }
}
```
```Python []
from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 0:
            raise ValueError("传入无效的参数")
        if size == 1:
            return nums[0]
        return self.__find_min(nums, 0, size - 1)

    def __find_min(self, nums, left, right):
        if left == right:
            return nums[left]
        if left + 1 == right:
            return min(nums[left], nums[right])
        mid = (left + right) >> 1

        if nums[mid] < nums[right]:
            return min(self.__find_min(nums, left, mid - 1), nums[mid])
        else:
            # nums[mid] > nums[right]
            # [4,5,6,7,8,1,2]
            return min(nums[left], self.__find_min(nums, mid + 1, right))
```