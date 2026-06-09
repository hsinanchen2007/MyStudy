#### 方法一：枚举

我们知道，对于给定的三个非负数 `a, b, c`，如果满足 `a + b > c, a + c > b, b + c > a`，那么 `a, b, c` 可以组成一个三角形。因此我们可以使用三重循环分别枚举 `a, b, c`，并检查是否满足上面的三个不等式。

```Java s[ol1]
public class Solution {
    public int triangleNumber(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            for (int j = i + 1; j < nums.length - 1; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    if (nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j] && nums[j] + nums[k] > nums[i])
                        count++;
                }
            }
        } I
        return count;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^3)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(1)$。

#### 方法二：二分查找

如果我们先将整个数组升序排序，那么在枚举 `a, b, c` 时，我们一定有 `a <= b <= c`，因此对于方法一中的三个不等式，`a + c > b` 和 `b + c > a` 一定都满足，只需要判断是否有 `a + b > c`（只有一种特殊情况，那就是 `a` 和 `b` 中至少有一个 `0`，那么此时无论 `c` 的值是多少，`a + b > c` 一定都不满足，因此我们只需要判断这个不等式即可）。

基于上面的优化，我们可以设计时间复杂度更低的算法。在排完序之后，我们使用二重循环枚举 `a` 和 `b`，由于数组是升序的，因此我们可以用二分查找的方法，找出最大的满足 `a + b > c` 的 `c`。设 `a, b, c` 在数组中对应的位置分别为 `i, j, k`，且满足 `i < j < k`，那么对于枚举的 `a` 和 `b`，满足条件的三元组个数为 `k - j`，这是因为 `nums[j + 1]` 到 `nums[k]` 都可以作为满足条件的 `c`。

<![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_BinarySlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_BinarySlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_BinarySlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_BinarySlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_BinarySlide5.PNG)>

我们还可以发现，在固定 `a` 时，随着 `b` 的递增，二分得到的位置 `k` 应该也递增，因此我们不必每次都在 `[j + 1 .. n - 1]` 的范围进行查找，而可以优化到 `[k0 .. n - 1]`，其中 `k0` 是上一次二分查找的结果。这个优化并不会改变时间复杂度。

```Java [sol2]
public class Solution {
    int binarySearch(int nums[], int l, int r, int x) {
        while (r >= l && r < nums.length) {
            int mid = (l + r) / 2;
            if (nums[mid] >= x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    public int triangleNumber(int[] nums) {
        int count = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.length - 1 && nums[i] != 0; j++) {
                k = binarySearch(nums, k, nums.length - 1, nums[i] + nums[j]);
                count += k - j - 1;
            }
        }
        return count;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2 \log N)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(\log N)$，为排序需要的空间。

#### 方法三：双指针

在方法二中，我们固定位置 `i, j` 后，用二分查找的方法找出满足条件的 `k`。事实上，我们也可以使用双指针的方法，其中一个指针表示 `j`，另一个指针表示 `k`，来找出对于每一个 `j`，满足条件的 `k` 的数目。

我们使用一重循环枚举 `i`。`j` 的初始值为 `i + 1`，`k` 的初始值为 `j + 1 = i + 2`。对于每个固定的 `j`，我们增加 `k` 的值，直到有 `nums[i] + nums[j] > nums[k]`，此时 `nums[j + 1]` 到 `nums[k - 1]` 都满足条件，因此给答案加上 `k - j - 1`。随后我们将 `j` 的值增加 `1`，但 `k` 不用从 `j + 1` 开始增加，而是从上一次的 `k` 开始增加即可。这样做的正确性在方法二中也有所表述，因为如果 `nums[i] + nums[j] > nums[k]` 成立，那么满足 `nums[i] + nums[j + 1] > nums[k1 + 1]` 条件的 `k1` 一定不小于 `k`。在每一次循环中，我们只会将 `j` 和 `k` 增加 $O(N)$ 次，因此时间复杂度为 $O(N^2)$。

<![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/611/Valid_Triangle_LinearSlide13.PNG)>

```Java [sol3]
public class Solution {
    public int triangleNumber(int[] nums) {
        int count = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.length - 1 && nums[i] != 0; j++) {
                while (k < nums.length && nums[i] + nums[j] > nums[k])
                    k++;
                count += k - j - 1;
            }
        }
        return count;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(\log N)$，为排序需要的空间。