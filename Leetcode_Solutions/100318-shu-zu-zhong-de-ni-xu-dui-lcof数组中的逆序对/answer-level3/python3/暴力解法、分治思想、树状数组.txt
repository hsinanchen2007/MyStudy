
类似问题：[315. 计算右侧小于当前元素的个数](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/)。

### 方法一：暴力解法

**参考代码 1**：

```Java []
public class Solution {

    /**
     * 暴力解法求逆序对，使用两种循环进行枚举，时间复杂度：O(n^2)
     *
     * @param nums
     */
    public int reversePairs(int[] nums) {
        int cnt = 0;
        int len = nums.length;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] > nums[j]) {
                    // System.out.println("找到的逆序对之一：" + nums[i] + " " + nums[j]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
```
```Python []
from typing import List


class Solution:

    def reversePairs(self, nums: List[int]) -> int:
        size = len(nums)
        if size < 2:
            return 0
        res = 0
        for i in range(0, size - 1):
            for j in range(i + 1, size):
                if nums[i] > nums[j]:
                    res += 1
        return res
```


### 方法二：借助归并排序统计逆序数（分治思想）

这种思想是暴力解法的优化，很经典也很有技巧性，是很多教材上都有介绍的方法，是需要掌握的，我是学习了很久归并排序，直到真的在 online judge 上做这个问题，才把它想明白的。

思路分析：

逆序对来源于 3 个部分：

+ 左边区间的逆序对
+ 右边区间的逆序对
+ 横跨两个区间的逆序对

借助归并排序算法，一边完成排序，一边完成逆序数的统计。**由于排序的作用，在归并的时候，可以一下子统计出某个元素与之前或者之后元素的逆序的个数。**

**注意**：统计逆序的时候，标准要统一，或者是在后有序数组出列的时候统计逆序数，或者是在前有序数组出列的时候统计逆序数。
**技巧**：使用小规模测试用例搞清楚边界问题。对逆序数问题不熟悉的朋友，需要自己先尝试在纸上写出具体的例子，计算应该怎样一次性统计出逆序的个数。如果出错了，再比对下面给出的做法。


下面提供两种写法：

1、后有序数组中元素出列的时候，计算逆序个数；
2、前有序数组中元素出列的时候，计算逆序个数。

![315-merge-sort-20.png](https://pic.leetcode-cn.com/6d170e1ac84234220d1ba12af625b61279170f61fd5d40abe94c97381e0aa633-315-merge-sort-20.png)

**参考代码 2**：

```Java []
public class Solution {

    // 后有序数组中元素出列的时候，计算逆序个数

    public int reversePairs(int[] nums) {
        int len = nums.length;
        if (len < 2) {
            return 0;
        }
        int[] temp = new int[len];
        return reversePairs(nums, 0, len - 1, temp);
    }

    /**
     * 计算在数组 nums 的索引区间 [left, right] 内统计逆序对
     *
     * @param nums  待统计的数组
     * @param left  待统计数组的左边界，可以取到
     * @param right 待统计数组的右边界，可以取到
     * @return
     */
    private int reversePairs(int[] nums, int left, int right, int[] temp) {
        // 极端情况下，就是只有 1 个元素的时候，这里只要写 == 就可以了，不必写大于
        if (left == right) {
            return 0;
        }

        int mid = (left + right) >>> 1;

        int leftPairs = reversePairs(nums, left, mid, temp);
        int rightPairs = reversePairs(nums, mid + 1, right, temp);

        int reversePairs = leftPairs + rightPairs;
        if (nums[mid] <= nums[mid + 1]) {
            return reversePairs;
        }

        int reverseCrossPairs = mergeAndCount(nums, left, mid, right, temp);
        return reversePairs + reverseCrossPairs;

    }

    /**
     * [left, mid] 有序，[mid + 1, right] 有序
     * @param nums
     * @param left
     * @param mid
     * @param right
     * @param temp
     * @return
     */
    private int mergeAndCount(int[] nums, int left, int mid, int right, int[] temp) {
        // 复制到辅助数组里，帮助我们完成统计
        for (int i = left; i <= right; i++) {
            temp[i] = nums[i];
        }

        int i = left;
        int j = mid + 1;
        int res = 0;
        for (int k = left; k <= right; k++) {
            if (i > mid) {
                // i 用完了，只能用 j
                nums[k] = temp[j];
                j++;
            } else if (j > right) {
                // j 用完了，只能用 i
                nums[k] = temp[i];
                i++;
            } else if (temp[i] <= temp[j]) {
                // 此时前数组元素出列，不统计逆序对
                nums[k] = temp[i];
                i++;
            } else {
                // 此时后数组元素出列，统计逆序对，快就快在这里，一次可以统计出一个区间的个数的逆序对
                nums[k] = temp[j];
                j++;
                res += (mid - i + 1);
            }
        }
        return res;
    }
}
```
```Python []
# 后有序数组中元素出列的时候，计算逆序个数

from typing import List


class Solution:

    def reversePairs(self, nums: List[int]) -> int:
        size = len(nums)
        if size < 2:
            return 0

        # 用于归并的辅助数组
        temp = [0 for _ in range(size)]
        return self.count_reverse_pairs(nums, 0, size - 1, temp)

    def count_reverse_pairs(self, nums, left, right, temp):
        # 在数组 nums 的区间 [left, right] 统计逆序对
        if left == right:
            return 0
        mid = (left + right) >> 1
        left_pairs = self.count_reverse_pairs(nums, left, mid, temp)
        right_pairs = self.count_reverse_pairs(nums, mid + 1, right, temp)

        reverse_pairs = left_pairs + right_pairs
        # 代码走到这里的时候，[left, mid] 和 [mid + 1, right] 已经完成了排序并且计算好逆序对

        if nums[mid] <= nums[mid + 1]:
            # 此时不用计算横跨两个区间的逆序对，直接返回 reverse_pairs
            return reverse_pairs

        reverse_cross_pairs = self.merge_and_count(nums, left, mid, right, temp)
        return reverse_pairs + reverse_cross_pairs

    def merge_and_count(self, nums, left, mid, right, temp):
        """
        [left, mid] 有序，[mid + 1, right] 有序

        前：[2, 3, 5, 8]，后：[4, 6, 7, 12]
        只在后面数组元素出列的时候，数一数前面这个数组还剩下多少个数字，
        由于"前"数组和"后"数组都有序，
        此时"前"数组剩下的元素个数 mid - i + 1 就是与"后"数组元素出列的这个元素构成的逆序对个数

        """
        for i in range(left, right + 1):
            temp[i] = nums[i]

        i = left
        j = mid + 1
        res = 0
        for k in range(left, right + 1):
            if i > mid:
                nums[k] = temp[j]
                j += 1
            elif j > right:
                nums[k] = temp[i]
                i += 1
            elif temp[i] <= temp[j]:
                # 此时前数组元素出列，不统计逆序对
                nums[k] = temp[i]
                i += 1
            else:
                # assert temp[i] > temp[j]
                # 此时后数组元素出列，统计逆序对，快就快在这里，一次可以统计出一个区间的个数的逆序对
                nums[k] = temp[j]
                j += 1
                # 例：[7, 8, 9][4, 6, 9]，4 与 7 以及 7 后面所有的数都构成逆序对
                res += (mid - i + 1)
        return res
```


![315-merge-sort-21.png](https://pic.leetcode-cn.com/e44db9d10484b9945984328d17077f6c70262eae8022c16cb25f51ba666b422f-315-merge-sort-21.png)

**参考代码 3**：

```Java []
public class Solution {

    // 前有序数组中元素出列的时候，计算逆序个数；

    public int reversePairs(int[] nums) {
        int len = nums.length;
        if (len < 2) {
            return 0;
        }
        int[] temp = new int[len];
        return reversePairs(nums, 0, len - 1, temp);
    }

    /**
     * 计算在数组 nums 的索引区间 [left, right] 内统计逆序对
     *
     * @param nums  待统计的数组
     * @param left  待统计数组的左边界，可以取到
     * @param right 待统计数组的右边界，可以取到
     * @return
     */
    private int reversePairs(int[] nums, int left, int right, int[] temp) {
        // 极端情况下，就是只有 1 个元素的时候，这里只要写 == 就可以了，不必写大于
        if (left == right) {
            return 0;
        }

        int mid = (left + right) >>> 1;

        int leftPairs = reversePairs(nums, left, mid, temp);
        int rightPairs = reversePairs(nums, mid + 1, right, temp);

        int reversePairs = leftPairs + rightPairs;
        if (nums[mid] <= nums[mid + 1]) {
            return reversePairs;
        }

        int reverseCrossPairs = mergeAndCount(nums, left, mid, right, temp);
        return reversePairs + reverseCrossPairs;

    }

    /**
     * [left, mid] 有序，[mid + 1, right] 有序
     *
     * @param nums
     * @param left
     * @param mid
     * @param right
     * @param temp
     * @return
     */
    private int mergeAndCount(int[] nums, int left, int mid, int right, int[] temp) {
        // 复制到辅助数组里，帮助我们完成统计
        for (int i = left; i <= right; i++) {
            temp[i] = nums[i];
        }

        int i = left;
        int j = mid + 1;
        int res = 0;
        for (int k = left; k <= right; k++) {
            if (i > mid) {
                // i 用完了，只能用 j
                nums[k] = temp[j];
                j++;
            } else if (j > right) {
                // j 用完了，只能用 i
                nums[k] = temp[i];
                i++;
                res += (right - mid);
            } else if (temp[i] <= temp[j]) {
                // 此时前数组元素出列，不统计逆序对
                nums[k] = temp[i];
                i++;
                res += (j - mid - 1);
            } else {
                // 此时后数组元素出列，统计逆序对，快就快在这里，一次可以统计出一个区间的个数的逆序对
                nums[k] = temp[j];
                j++;
            }
        }
        return res;
    }
}
```
```Python []
# 前有序数组中元素出列的时候，计算逆序个数

from typing import List


class Solution:

    def reversePairs(self, nums: List[int]) -> int:
        size = len(nums)
        if size < 2:
            return 0

        temp = [0 for _ in range(size)]
        return self.reverse_pairs(nums, 0, size - 1, temp)

    def reverse_pairs(self, nums, left, right, temp):
        """
        在数组 nums 的区间 [l,r] 统计逆序对
        :param nums:
        :param left: 待统计数组的左边界，可以取到
        :param right: 待统计数组的右边界，可以取到
        :param temp:
        :return:
        """
        if left == right:
            return 0
        mid = (left + right) >> 1
        left_pairs = self.reverse_pairs(nums, left, mid, temp)
        right_pairs = self.reverse_pairs(nums, mid + 1, right, temp)

        reverse_pairs = left_pairs + right_pairs
        if nums[mid] <= nums[mid + 1]:
            return reverse_pairs

        reverse_cross_pairs = self.merge_and_count(nums, left, mid, right, temp)
        return reverse_pairs + reverse_cross_pairs

    def merge_and_count(self, nums, left, mid, right, temp):
        """
        [left, mid] 有序，[mid + 1, right] 有序

        前：[2, 3, 5, 8]，后：[4, 6, 7, 12]
        我们只需要在后面数组元素出列的时候，数一数前面这个数组还剩下多少个数字，
        因为"前"数组和"后"数组都有序，
        因此，"前"数组剩下的元素个数 mid - i + 1 就是与"后"数组元素出列的这个元素构成的逆序对个数

        """
        for i in range(left, right + 1):
            temp[i] = nums[i]

        i = left
        j = mid + 1

        res = 0
        for k in range(left, right + 1):
            if i > mid:
                nums[k] = temp[j]
                j += 1
            elif j > right:
                nums[k] = temp[i]
                i += 1

                res += (right - mid)
            elif temp[i] <= temp[j]:
                nums[k] = temp[i]
                i += 1

                res += (j - mid - 1)
            else:
                assert temp[i] > temp[j]
                nums[k] = temp[j]
                j += 1
        return res
```


### 方法三：树状数组

用树状数组解决逆序数问题，也是一个经典的做法。具体的做法是从后向前扫描，边统计边往树状数组里面添加元素。因为涉及大小关系，所以要排个序，并且给出排名（`rank`），这一步操作也叫“离散化”。

**参考代码 4**：

```Python []
from typing import List


class Solution:

    def reversePairs(self, nums: List[int]) -> int:

        class FenwickTree:
            def __init__(self, n):
                self.size = n
                self.tree = [0 for _ in range(n + 1)]

            def __lowbit(self, index):
                return index & (-index)

            # 单点更新：从下到上，最多到 len，可以取等
            def update(self, index, delta):
                while index <= self.size:
                    self.tree[index] += delta
                    index += self.__lowbit(index)

            # 区间查询：从上到下，最少到 1，可以取等
            def query(self, index):
                res = 0
                while index > 0:
                    res += self.tree[index]
                    index -= self.__lowbit(index)
                return res

        # 特判
        size = len(nums)
        if size < 2:
            return 0

        # 原始数组去除重复以后从小到大排序，这一步叫做离散化
        s = list(set(nums))

        # 构建最小堆，因为从小到大一个一个拿出来，用堆比较合适
        import heapq
        heapq.heapify(s)

        # 由数字查排名
        rank_map = dict()
        rank = 1
        # 不重复数字的个数
        rank_map_size = len(s)
        for _ in range(rank_map_size):
            num = heapq.heappop(s)
            rank_map[num] = rank
            rank += 1

        res = 0
        # 树状数组只要不重复数字个数这么多空间就够了
        ft = FenwickTree(rank_map_size)

        # 从后向前看，拿出一个数字来，就更新一下，然后向前查询比它小的个数
        for i in range(size - 1, -1, -1):
            rank = rank_map[nums[i]]
            ft.update(rank, 1)
            res += ft.query(rank - 1)
        return res
```