## 解法：二分查找

> 注意：题目要求时间复杂度为$O(\log n)$。


这道题实际上是原始的二分查找题目的拓展。在原始的二分查找中，整体数组都是有序的，但在该题目中，由于对数组进行了旋转，数组变成了部分有序。

但我们仍旧可以使用二分查找来求解该题，不过要对判断目标元素位于左侧还是右侧的代码进行扩展。下面给出判断目标元素位于左侧还是右侧的代码：

为了理清楚该部分代码的思路，需要对原始的数组进行抽象，将原始数组的元素大小顺序抽象为下图：

![41585970122_.pic_hd.jpg](https://pic.leetcode-cn.com/5eb0356b558cd67ef3b2f43b3ae53fe70dd7841cdf698ac9d91ae0c4cabad427-41585970122_.pic_hd.jpg)


* **首先判断当前元素区间中是否包含转折点**。如果区间起点大于区间终点，则说明包含转折点：
  * **判断被被选中的元素位于转折点左侧还是右侧**。如果被选中的元素大于等于区间起点，则说明位于转折点左侧：
    * **判断目标元素位于被选中的元素的左侧还是右侧**：如果目标元素小于被选中元素且大于等于区间起点，则说明目标元素位于被选中元素的左侧；
    * 否则位于右侧。
  * **否则被选中的元素位于转折点右侧**：
    * **判断目标元素位于被选中的元素的左侧还是右侧**：如果目标元素大于被选中的元素且小于等于区间终点，则说明目标元素位于被选中元素的右侧；
    * 否则位于左侧。
* 否则，不包含转折点，按照常规二分查找的方法进行判断即可。

代码如下：

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start_index = 0;
        int end_index = nums.size() - 1;

        int middle_index = start_index + (end_index - start_index) / 2;
        while (start_index <= end_index && nums[middle_index] != target) {
            if (inLeft(nums, middle_index, target, start_index, end_index)) {
                end_index = middle_index - 1;
            } else {
                start_index = middle_index + 1;
            }
            middle_index = start_index + (end_index - start_index) / 2;
        }
        int result = middle_index;
        if (start_index > end_index)
            result = -1;
        return result;
    }

    // 判断目标点是否位于index左侧
    bool inLeft(const vector<int>& nums, int index, int target, int start_index, int end_index) {
        bool result;
        if (nums[start_index] > nums[end_index]) {  // 区间内包含转折点
            if (nums[index] >= nums[start_index]) {  // 被选中的坐标位于转折点左侧
                if (nums[index] > target && nums[start_index] <= target)
                    result = true;
                else
                    result = false;
            } else {  // 被选中的坐标位于转折点右侧
                if (nums[index] < target && nums[end_index] >= target)
                    result = false;
                else
                    result = true;
            }
        } else {  // 区间内不包含转折点
            if (nums[index] > target)
                result = true;
            else
                result = false;
        }

        return result;
    }
};
```

