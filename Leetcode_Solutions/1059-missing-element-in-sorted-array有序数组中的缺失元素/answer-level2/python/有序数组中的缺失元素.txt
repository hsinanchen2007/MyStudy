#### 方法一：线性扫描

我们用函数 `missing(idx)` 表示到 `A[idx]` 为止总共缺失的数字个数，下图给出了一个例子，数组为 `[4, 7, 9, 10]`，缺失的数字为 `[5, 6, 8]`，到数组中的数字 `7, 9, 10` 为止缺失的数字个数分别为 `2, 3, 3` 个。

![fig](https://pic.leetcode-cn.com/Figures/1060/function.png){:width=500}
{:align=center}

如果我们能得到所有的 `missing(idx)`，那么我们只要对其进行线性扫描就可以知道第 `K` 个缺失的数字了。具体来说，如果有 `missing(idx - 1) < K <= missing(idx)`，那么就说明，第 `K` 个缺失的数字在 `A[idx - 1]` 和 `A[idx]` 之间，并且它比 `A[idx - 1]` 大 `K - missing(idx)`。

![fic](https://pic.leetcode-cn.com/Figures/1060/algor.png){:width=500}
{:align=center}

而计算出所有 `missing(idx)` 的方法也很简单，从 `A[0]` 到 `A[idx]` 应该有 `A[idx] - A[0] + 1` 个数字，而实际上根据下标，只有 `idx + 1` 个数字，因此缺失的数字个数为上面两个式子之差，即 `A[idx] - A[0] - idx`。

![pic](https://pic.leetcode-cn.com/Figures/1060/missing.png){:width=500}
{:align=center}

```Java [sol1]
class Solution {
    // Return how many numbers are missing until nums[idx]
    int missing(int idx, int[] nums) {
        return nums[idx] - nums[0] - idx;
    }

    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        // If kth missing number is larger than 
        // the last element of the array
        if (k > missing(n - 1, nums))
            return nums[n - 1] + k - missing(n - 1, nums);

        int idx = 1;
        // find idx such that 
        // missing(idx - 1) < k <= missing(idx)
        while (missing(idx, nums) < k) idx++;

        // kth missing number is larger than nums[idx - 1]
        // and smaller than nums[idx]
        return nums[idx - 1] + k - missing(idx - 1, nums);
    }
}
```

```Python [sol1]
class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        # Return how many numbers are missing until nums[idx]
        missing = lambda idx: nums[idx] - nums[0] - idx
                
        n = len(nums)
        # If kth missing number is larger than 
        # the last element of the array
        if k > missing(n - 1):
            return nums[-1] + k - missing(n - 1) 

        idx = 1
        # find idx such that 
        # missing(idx - 1) < k <= missing(idx)
        while missing(idx) < k:
            idx += 1

        # kth missing number is larger than nums[idx - 1]
        # and smaller than nums[idx]
        return nums[idx - 1] + k - missing(idx - 1)
```

**复杂度分析**

* 时间复杂度：$O(N)$，最多只会遍历整个数组一次。

* 空间复杂度：$O(1)$。

#### 方法二：二分查找

**分析**

在方法一中，我们是通过线性扫描的方法找到 `missing(idx - 1) < K <= missing(idx)` 对应的 `idx` 的。事实上，由于 `missing(idx)` 是单调不减的，我们可以通过二分查找的方法找到满足条件的 `idx`，并将时间复杂度降低到 $O(\log N)$。

![fif](https://pic.leetcode-cn.com/Figures/1060/inary.png){:width=500}
{:align=center}

```Java [sol2]
class Solution {
  // Return how many numbers are missing until nums[idx]
  int missing(int idx, int[] nums) {
      return nums[idx] - nums[0] - idx;
  }

  public int missingElement(int[] nums, int k) {
      int n = nums.length;
      // If kth missing number is larger than 
      // the last element of the array
      if (k > missing(n - 1, nums))
          return nums[n - 1] + k - missing(n - 1, nums);

      int left = 0, right = n - 1, pivot;
      // find left = right index such that 
      // missing(left - 1) < k <= missing(left)
      while (left != right) {
          pivot = left + (right - left) / 2;

          if (missing(pivot, nums) < k) left = pivot + 1;
          else right = pivot;
      }

      // kth missing number is larger than nums[idx - 1]
      // and smaller than nums[idx]
      return nums[left - 1] + k - missing(left - 1, nums);
  }
}
```

```Python [sol2]
class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        # Return how many numbers are missing until nums[idx]
        missing = lambda idx: nums[idx] - nums[0] - idx
            
        n = len(nums)
        # If kth missing number is larger than 
        # the last element of the array
        if k > missing(n - 1):
            return nums[-1] + k - missing(n - 1) 
        
        left, right = 0, n - 1
        # find left = right index such that 
        # missing(left - 1) < k <= missing(left)
        while left != right:
            pivot = left + (right - left) // 2
            
            if missing(pivot) < k:
                left = pivot + 1
            else:
                right = pivot 
        
        # kth missing number is larger than nums[left - 1]
        # and smaller than nums[left]
        return nums[left - 1] + k - missing(left - 1) 
```

**复杂度分析**

* 时间复杂度：$O(\log N)$。

* 空间复杂度：$O(1)$。