#### 方法一：二分查找

**思路**
 
假设有一个递增数组 `L`，现在这个数组根据某个 _未知中心点_ 旋转得到数组 `L'`。要求找到这个旋转排序数组中的 _最小值_ ， 也就是原始数组 `L` 中的第一个值 `L[0]`。

这道题看上去跟 _在排序数组中查找数字_ 这类问题很相似，而这类问题一般用 **二分查找** 来实现，直觉上这道题也可以用二分查找来解决。

确实这是一个正确的思路，为了讲清楚这个算法，我们将该数组可视化，下图中的 X 轴表示元素在数组中的下标，Y 轴表示元素的值。

![pic](https://pic.leetcode-cn.com/Figures/154/154_axis.png)

_这个算法的主结构跟二分查找是一样的。_ ：

- 维护两个指针 `low`、`high`，使其代表查找范围的左边界和右边界。
- 移动指针来缩小查找范围，通常将指针移动到 `low`、`high` 的中间(`pivot = (low + high)/2`)。这样查找范围就可以缩小一半，这也是二分查找名字的由来。
- 在找到目标元素或者两个指针重合时(`low == high`)，算法终止。

**算法**

在传统的二分查找中，会将中轴元素(`nums[pivot]`)与目标元素相比较。但在这个问题里面，需要将中轴元素与右边界元素(`nums[high]`)相比较。

>二分查找算法的难点在于如何更新左右边界指针。

下面将分析所有可能的三种比较结果，并给出更新指针的方法：

>1）`nums[pivot] < nums[high]`

![pic](https://pic.leetcode-cn.com/Figures/154/154_case_1.png)

- 中轴元素跟右边界元素在 _同一半边_ 。
- 这时候最小元素在中轴元素 _左边_ ，将右边界指针移动到中轴元素位置（`high = pivot`）。

>2）`nums[pivot] > nums[high]`

![pic](https://pic.leetcode-cn.com/Figures/154/154_case_2.png)

- 中轴元素跟右边界届元素在 _不同半边_ 。
- 这时候最小元素在中轴元素 _右边_ ，将下届指针移动到中轴元素位置右边（`low = pivot + 1`）。 

>3）`nums[pivot] == nums[high]` 

![pic](https://pic.leetcode-cn.com/Figures/154/154_case_3_ii.png)

- 在这种情况下，不能确定最小元素在中轴元素的左边还是右边。
- 为了缩小查找范围，安全的方法是将右边界指针减一（`high = high - 1`）。
- 上述策略可以有效地避免死循环，同时可以保证永远不会跳过最小元素。

综上所述，这个算法跟二分查找有两处不同：

- 这里我们将中轴元素与右边界元素相比较，传统的二分查找将中轴元素与目标元素相对比。
- 当比较结果相同时，这里我们将左移右边界指针，而在传统的二分查找中直接返回结果。

```python [solution1-Python]
class Solution:
    def findMin(self, nums: List[int]) -> int:    
        low = 0
        high = len(nums)-1
        while high > low:
            pivot = low + (high - low) // 2
            # risk of overflow: pivot = (low + high) // 2
            # Case 1):
            if nums[pivot] < nums[high]:
                high = pivot 
                # alternative: high = pivot - 1
                # too aggressive to move the `high` index,
                # it won't work for the test case of [3, 1, 3]
            # Case 2):
            elif nums[pivot] > nums[high]:
                low = pivot + 1
            # Case 3):
            else:
                high -= 1
        # the 'low' and 'high' index converge to the inflection point.
        return nums[low]
```

```java [solution1-Java]
class Solution {
  public int findMin(int[] nums) {
    int low = 0, high = nums.length - 1;

    while (low < high) {
      int pivot = low + (high - low) / 2;
      if (nums[pivot] < nums[high])
        high = pivot;
      else if (nums[pivot] > nums[high])
        low = pivot + 1;
      else
        high -= 1;
    }
    return nums[low];
  }
}
```

**复杂度分析**
* 时间复杂度：平均时间复杂度为 $O(\log_{2}{N})$，其中 $N$ 为数组长度。但是在最坏情况下，也就是数组中包含相同元素时(`nums[pivot]==nums[high]`)，需要逐个遍历元素，复杂度为 $O(N)$。

* 空间复杂度：$O(1)$。

**讨论**

>这个问题是 [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/) 的 follow-up，不同点在于数组中可能包含重复数字。

_如果面试官问 “允许数组中元素重复会影响算法的时间复杂度嘛？为什么会影响？怎么影响的？”_

其实可以把问题 [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/) 看成这个问题的一个特例。这道题的所有解法也都适用于 [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)，只是永远不会进入 `nums[pivot] == nums[high]` 的分支。也正是因为可能包含重复数字，在 `nums[pivot] == nums[high]` 分支下才会导致最差时间复杂度为 $O(N)$。

>有人可能会想，在 `nums[pivot] == nums[high]` 时，是否可以将对 `high` 指针的移动（`high -= 1`）改成对 `low` 指针的移动(`low += 1`)。

答案是不行，举个例子，在输入为 `[1, 3, 3]` 时，如果移动 `low` 指针，就会跳过正确答案。

>又有人可能会想，在调整 `low` 指针的时候是让 `low = pivot + 1` 来缩小查找范围，那么为什么在调整 `high` 指针的时候用 `high = pivot` 而不是 `high = pivot - 1`。又或者，为什么用 `low <= high` 来判断，而不是用`low < high`?

实际上，二分搜索有很多种实现方式，它们之间的主要区别就在设置边界指针和循环条件上。边界指针的更新方法要跟循环条件相匹配，在套模板的时候要注意不要将多种二分搜索的实现混起来。

最后再提一点，计算中间点是用 `pivot = low + (high-low)/2` 来计算的，而不是直接 `pivot = (high + low)/2`，这主要是为了防止两个数字相加后发生溢出。