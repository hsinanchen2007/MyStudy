#### 方法一：使用排序寻找中位数

假设最终数组 `a` 中的每个数均为 `x`，那么需要移动的次数即为 `|a[0] - x| + |a[1] - x| + ... + |a[n-1] - x|`。如果我们把数组 `a` 中的每个数看成水平轴上的一个点，那么根据上面的移动次数公式，我们需要找到在水平轴上找到一个点 `x`，使得这 `N` 个点到 `x` 的距离之和最小。

这是一个经典的数学问题，当 `x` 为这个 `N` 个数的中位数时，可以使得距离最小。具体地，若 `N` 为奇数，则 `x` 必须为这 `N` 个数中的唯一中位数；若 `N` 为偶数，中间的两个数为 `p` 和 `q`，中位数为 `(p + q) / 2`，此时 `x` 只要是区间 `[p, q]` 中的任意一个数即可。

因此，我们只需要找到这个 `N` 个数的中位数，并计算距离之和。我们可以直接将数组进行排序，这样就直接得到了中位数。

<![1000](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves1Slide1.JPG),![1000](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves1Slide2.JPG),![1000](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves1Slide3.JPG),![1000](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves1Slide4.JPG),![1000](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves1Slide5.JPG),![1000](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves1Slide6.JPG),![1000](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves1Slide7.JPG),![1000](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves1Slide8.JPG)>

```Java [sol1]
public class Solution {
    public int minMoves2(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for (int num : nums) {
            sum += Math.abs(nums[nums.length / 2] - num);
        }
        return sum;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(\log N)$，为排序需要使用的空间。

#### 方法二：使用快速选择寻找中位数

我们也可以使用快速选择（Quick-Select）算法找到数组中的中位数。

快速选择算法借鉴了快速排序的思想，在一轮快速排序中，基准元素（pivot）的左侧有 `p` 个元素，右侧有 `q` 个元素，我们需要找第 `k` 小的元素。如果 `k = p + 1`，那么基准元素即为第 `k` 小的元素；如果 `k <= p`，那么第 `k` 小的元素出现在左侧的 `p` 个元素中，因此我们并不需要对右侧的元素进行排序；如果 `k > p + 1`，那么第 `k` 小的元素出现在右侧的 `q` 个元素中，因此我们并不需要对左侧的元素进行排序。

因此，快速选择算法相当于每次只对一侧的元素进行排序，而舍弃了另一侧的元素。这样我们就可以在平均 $O(N)$ 的时间复杂度找到数组中第 `k` 小的元素。在本题中，我们只需要知道中位数对应的 `k`，再使用快速选择算法找到底 `k` 小的元素即可。

关于快速选择算法，可以参考题目 (215. 数组中的第K个最大元素)[https://leetcode-cn.com/problems/kth-largest-element-in-an-array/]。
 
<![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide1.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide2.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide3.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide4.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide5.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide6.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide7.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide8.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide9.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide10.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide11.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide12.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide13.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide14.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide15.JPG),![1400](https://pic.leetcode-cn.com/Figures/462_Minimum_Moves2Slide16.JPG)>

```Java [sol2]
public class Solution {
    public void swap(int[] list, int i, int pivot_index) {
        int temp = list[i];
        list[i] = list[pivot_index];
        list[pivot_index] = temp;
    }
    public int partition(int[] list, int left, int right) {
        int pivotValue = list[right];
        int i = left;
        for (int j = left; j <= right; j++) {
            if (list[j] < pivotValue) {
                swap(list, i, j);
                i++;
            }
        }
        swap(list, right, i);
        return i;
    }
    int select(int[] list, int left, int right, int k) {
        if (left == right) {
            return list[left];
        }
        int pivotIndex = partition(list, left, right);
        if (k == pivotIndex) {
            return list[k];
        } else if (k < pivotIndex) {
            return select(list, left, pivotIndex - 1, k);
        } else {
            return select(list, pivotIndex + 1, right, k);
        }
    }
    public int minMoves2(int[] nums) {
        int sum = 0;
        int median = select(nums, 0, nums.length - 1, nums.length / 2);

        for (int num : nums) {
            sum += Math.abs(median - num);
        }
        return sum;
    }
}
```

**复杂度分析**

* 时间复杂度：平均为 $O(N)$，但在最坏情况下会达到 $O(N^2)$，这是快速排序本身的性质导致的。

* 空间复杂度：$O(\log N)$，为快速选择需要使用的空间。