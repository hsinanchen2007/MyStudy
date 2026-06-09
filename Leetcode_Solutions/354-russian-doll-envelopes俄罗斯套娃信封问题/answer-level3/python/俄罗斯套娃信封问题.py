####  方法：排序 + 最长递增子序列
该问题为最长递增子序列的二维问题。

我们要找到最长的序列，且满足 `seq[i+1]` 中的元素大于 `seq[i]` 中的元素。

该问题是输入是按任意顺序排列的——我们不能直接套用标准的 LIS 算法，需要先对数据进行排序。我们如何对数据进行排序，以便我们的 LIS 算法总能找到最佳答案？


我们可以在[这里](https://leetcode-cn.com/problems/longest-increasing-subsequence/?utm_source=LCUS&utm_medium=ip_redirect_q_uns&utm_campaign=transfer2china)找到最长递增子序列的解决方法。如果您不熟悉该算法，请先理解该算法，因为它是解决此问题的前提条件。

**算法：**
假设我们知道了信封套娃顺序，那么从里向外的顺序必须是按 `w` 升序排序的子序列。

在对信封按 `w` 进行排序以后，我们可以找到 `h` 上最长递增子序列的长度。、

我们考虑输入 `[[1，3]，[1，4]，[1，5]，[2，3]]`，如果我们直接对 `h` 进行 LIS 算法，我们将会得到 `[3，4，5]`，显然这不是我们想要的答案，因为 `w` 相同的信封是不能够套娃的。

为了解决这个问题。我们可以按 `w` 进行升序排序，若 `w` 相同则按 `h` 降序排序。则上述输入排序后为 `[[1，5]，[1，4]，[1，3]，[2，3]]`，再对 `h` 进行 LIS 算法可以得到 `[5]`，长度为 1，是正确的答案。这个例子可能不明显。

我们将输入改为 `[[1，5]，[1，4]，[1，2]，[2，3]]`。则提取 `h` 为 `[5，4，2，3]`。我们对 `h` 进行 LIS 算法将得到 `[2，3]`，是正确的答案。


```python [solution1-Python]
from bisect import bisect_left

class Solution:
    def maxEnvelopes(self, arr: List[List[int]]) -> int:
        # sort increasing in first dimension and decreasing on second
        arr.sort(key=lambda x: (x[0], -x[1]))

        def lis(nums):
            dp = []
            for i in range(len(nums)):
                idx = bisect_left(dp, nums[i])
                if idx == len(dp):
                    dp.append(nums[i])
                else:
                    dp[idx] = nums[i]
            return len(dp)
        # extract the second dimension and run the LIS
        return lis([i[1] for i in arr])
```

```java [solution1-Java]
class Solution {

    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int len = 0;
        for (int num : nums) {
            int i = Arrays.binarySearch(dp, 0, len, num);
            if (i < 0) {
                i = -(i + 1);
            }
            dp[i] = num;
            if (i == len) {
                len++;
            }
        }
        return len;
    }

    public int maxEnvelopes(int[][] envelopes) {
        // sort on increasing in first dimension and decreasing in second
        Arrays.sort(envelopes, new Comparator<int[]>() {
            public int compare(int[] arr1, int[] arr2) {
                if (arr1[0] == arr2[0]) {
                    return arr2[1] - arr1[1];
                } else {
                    return arr1[0] - arr2[0];
                }
           }
        });
        // extract the second dimension and run LIS
        int[] secondDim = new int[envelopes.length];
        for (int i = 0; i < envelopes.length; ++i) secondDim[i] = envelopes[i][1];
        return lengthOfLIS(secondDim);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N \log N)$。其中 $N$ 是输入数组的长度。排序和 LIS 算法都是 $O(N \log N)$。
* 空间复杂度：$O(N)$，`lis` 函数需要一个数组 `dp`，它的大小可达 $N$。另外，我们使用的排序算法也可能需要额外的空间。