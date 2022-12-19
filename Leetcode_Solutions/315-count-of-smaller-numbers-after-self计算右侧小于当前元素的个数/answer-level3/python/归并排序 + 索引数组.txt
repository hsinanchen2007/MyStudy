### 归并排序 + 索引数组

如果有学习过一个数组的“逆序对”如何计算的朋友，对求解这道问题应该不陌生。

<![image.png](https://pic.leetcode-cn.com/a8a8a0cb737e1100766f9b406e141f3cff0918b85c6443071456a34f50faf164-image.png),![image.png](https://pic.leetcode-cn.com/72f9f4e33a03726166812906eb63194dd81a2b02b969d86bfecaff6ca1faf7e3-image.png),![image.png](https://pic.leetcode-cn.com/b4b3251eaed3bbed98a5d8792d694aec4b95c3079d1e36d65581b56b11f10d94-image.png),![image.png](https://pic.leetcode-cn.com/7cdcdc78c3f2f056bf5c7e1fe116de0d1e2066bb8839c44a8b33755389dc63ac-image.png),![image.png](https://pic.leetcode-cn.com/fec652674db89aa8acda91e2ce84203168769f5d6d720797045dcc5865160a01-image.png),![image.png](https://pic.leetcode-cn.com/4b70e0bcf059b3dcbbea7ab46eb22314c65cc2bed74f17ef74a2eb5c0f73090b-image.png),![image.png](https://pic.leetcode-cn.com/2cd9099d60d56edf0c66ff41bdd6859c5327e6b39d4225449bff299c82073635-image.png),![image.png](https://pic.leetcode-cn.com/7babb0fcd83ce8f9b6dd5da2ee187268ad680c26bcc3ca5d6ab96aed4acde679-image.png),![image.png](https://pic.leetcode-cn.com/5de2c79dd9eeec39ceb44ad597a26da192060c29cf9845868243c2b6390f0e06-image.png),![image.png](https://pic.leetcode-cn.com/4e4a67de3359c904345bd27bfc78f0a41f6c438fd6275a8b6f3dc3c3d46abfcd-image.png),![image.png](https://pic.leetcode-cn.com/00082337651ccbf3115aaa5b3f5a66a59d5190c3d9f76f057ad92d44fecc35f3-image.png),![image.png](https://pic.leetcode-cn.com/5e4b3bcdd091e08cee30a8269856ec310d3cec16f784866c59c0e77f9670ad71-image.png),![image.png](https://pic.leetcode-cn.com/e49182d0eae38f0f762f614fed6f52b9f2eca9efd9554bb36bcc21137bdd9d4e-image.png),![image.png](https://pic.leetcode-cn.com/cc9d7b17dbfc5faced0d388271e9e4079e43c8ce5851d33ebe28d94fcacda3cc-image.png),![image.png](https://pic.leetcode-cn.com/9a8f56b50225b81c906d19d8929591fe34f8c1c3eb45966d6c8dd81b22b9450d-image.png),![image.png](https://pic.leetcode-cn.com/7a23dc334b01e693f787d3b3c3d98a685e5b6f48fd02b090985cd291cdc78cf6-image.png),![image.png](https://pic.leetcode-cn.com/5f01a5dd1866e4d728cd395232d1d52451e949030af6085ed76ade6a3c0f562a-image.png),![image.png](https://pic.leetcode-cn.com/b4f55e533b0fcf8166964cfb496c8e25393d4cfefb4dce3714b8806827f9b270-image.png),![image.png](https://pic.leetcode-cn.com/c46a294e23a05d320e6903a932932fecd130bdeb78c718fe9a3b35e34d2f0056-image.png)>



求解 “逆序对” 的关键在于：**当其中一个数字放进最终归并以后的有序数组中的时候，这个数字与之前看过的数字个数（或者是未看过的数字个数）可以直接统计出来，而不必一个一个数”**。

![315-1.png](https://pic.leetcode-cn.com/729ec13f1387a428a264c143def1ff0e211952fa5c4f22424dbfb760509fa2bc-315-1.png)

“归并排序” 完成以后，原数组的 “逆序数” 也数出来了。

**下面这句话很重要**：

> 回到本题，本题让我们求 “在一个数组的某个元素的右边，比自己小的元素的个数”，因此，我们就 **应该在 “前有序数组” 的元素出列的时候，数一数 “后有序数组” 已经出列了多少元素**，因为这些已经出列的元素都比当前出列的元素要小（或者等于）。

**发现问题**

不过题目中要求我们要具体计算到元素级别。“归并排序” 完成以后，原始数组的位置就已经变化了，因此如何定位元素是关键。

**想一想这一类问题是怎么解决的**

**一个元素在算法的执行过程中位置发生变化，我们还想定位它**，这样的场景我们在 “最小索引堆” 中曾经学习过，从中得到启发，不妨也设置一个 “索引数组” 吧。使用 “索引数组” 的关键在于：

> **“原始数组” 不变，用于比较两个元素的大小，真正位置变换的是 “索引数组”**。


下面我尝试解释一下 “索引数组” 的使用方法：

![315-2.png](https://pic.leetcode-cn.com/84953655bc88f3c6342d71a79895270675e9034593a713f833fd3edf1c39d231-315-2.png)


为了完成 “索引数组” 的归并，我们还需要一个 “索引数组” 长度的临时数组，把索引数组的值复制过去，比较完成以后，再赋值回 “索引数组”。具体请看下面的代码。

**总结：**

> 1、我们借助计算 “逆序数” 的思路完成本题，关键在于这里我们只能在 “前有序数组” 出列的时候计算逆序数；
如果题目让我们计算 “`nums[i]` 左侧小于 `nums[i]` 的元素的数量” 可以在 “后有序数组” 出列的时候计算逆序数；
> 
> 2、体会 “索引数组” 这个使用技巧。

**编码注意事项**

一、可以复习一下 “归并排序” 的细节。

1、如果 “前有序数组” 和 “后有序数组” 直接合并的时候，就有序，就不必归并；

2、在 “归并” 的时候，全局使用一个临时存储数组，而不必每一个归并都新建临时的存储空间。

二、出列一个元素的时候，马上得到右边比自己小的元素的个数，是通过不同的指针之间的距离得到的。

**在编码的时候，建议在草稿纸上写写画画，用具体的数值带进去，才能确保你计算的指针之间的距离正确**。例如我写的 Python 代码 `res[indexes[i]] += (right - mid)` 和 `res[indexes[i]] += (r - mid - 1)` 这两句代码的计算，我就是在草稿纸上画出来的。

三、如果你写过 “逆序数” 的计算的代码，你就会发现，“逆序数” 的计算可以在 “前有序数组” 元素出列的时候计算逆序数，也可以在 “后有序数组” 元素出列的时候计算逆序数，你可以比较一下它们在编码时候的不同之处。

![inverse-pairs-1.png](https://pic.leetcode-cn.com/dab4062c5b86895c7ce2fa4ae4902443692bd33f8648d4420609d00d0171c0ff-inverse-pairs-1.png)

![inverse-pairs-2.png](https://pic.leetcode-cn.com/0d5881f4ed023caafc73baf6bd7ce0bca265bea5c1d00215d506de8be2fafb18-inverse-pairs-2.png)

参考代码：

```Python []
class Solution:
    def countSmaller(self, nums):
        size = len(nums)
        if size == 0:
            return []
        if size == 1:
            return [0]

        temp = [None for _ in range(size)]
        indexes = [i for i in range(size)]
        res = [0 for _ in range(size)]

        self.__helper(nums, 0, size - 1, temp, indexes, res)
        return res

    def __helper(self, nums, left, right, temp, indexes, res):
        if left == right:
            return
        mid = left + (right - left) // 2

        # 计算一下左边
        self.__helper(nums, left, mid, temp, indexes, res)
        # 计算一下右边
        self.__helper(nums, mid + 1, right, temp, indexes, res)

        if nums[indexes[mid]] <= nums[indexes[mid + 1]]:
            return
        self.__sort_and_count_smaller(nums, left, mid, right, temp, indexes, res)

    def __sort_and_count_smaller(self, nums, left, mid, right, temp, indexes, res):
        # [left,mid] 前有序数组
        # [mid+1,right] 后有序数组

        # 先拷贝，再合并

        for i in range(left, right + 1):
            temp[i] = indexes[i]

        l = left
        r = mid + 1
        for i in range(left, right + 1):
            if l > mid:
                # l 用完，就拼命使用 r
                # [1,2,3,4] [5,6,7,8]
                indexes[i] = temp[r]
                r += 1
            elif r > right:
                # r 用完，就拼命使用 l
                # [6,7,8,9] [1,2,3,4]
                indexes[i] = temp[l]
                l += 1
                # 注意：此时前面剩下的数，比后面所有的数都大
                res[indexes[i]] += (right - mid)
            elif nums[temp[l]] <= nums[temp[r]]:
                # [3,5,7,9] [4,6,8,10]
                indexes[i] = temp[l]
                l += 1
                # 注意：
                res[indexes[i]] += (r - mid - 1)
            else:
                assert nums[temp[l]] > nums[temp[r]]
                # 上面两种情况只在其中一种统计就可以了
                # [3,5,7,9] [4,6,8,10]
                indexes[i] = temp[r]
                r += 1
```
```Java []
import java.util.ArrayList;
import java.util.List;

public class Solution {

    private int[] temp;
    private int[] counter;
    private int[] indexes;

    public List<Integer> countSmaller(int[] nums) {
        List<Integer> res = new ArrayList<>();
        int len = nums.length;
        if (len == 0) {
            return res;
        }
        temp = new int[len];
        counter = new int[len];
        indexes = new int[len];
        for (int i = 0; i < len; i++) {
            indexes[i] = i;
        }
        mergeAndCountSmaller(nums, 0, len - 1);
        for (int i = 0; i < len; i++) {
            res.add(counter[i]);
        }
        return res;
    }

    /**
     * 针对数组 nums 指定的区间 [l, r] 进行归并排序，在排序的过程中完成统计任务
     *
     * @param nums
     * @param l
     * @param r
     */
    private void mergeAndCountSmaller(int[] nums, int l, int r) {
        if (l == r) {
            // 数组只有一个元素的时候，没有比较，不统计
            return;
        }
        int mid = l + (r - l) / 2;
        mergeAndCountSmaller(nums, l, mid);
        mergeAndCountSmaller(nums, mid + 1, r);
        // 归并排序的优化，同样适用于该问题
        // 如果索引数组有序，就没有必要再继续计算了
        if (nums[indexes[mid]] > nums[indexes[mid + 1]]) {
            mergeOfTwoSortedArrAndCountSmaller(nums, l, mid, r);
        }
    }

    /**
     * [l, mid] 是排好序的
     * [mid + 1, r] 是排好序的
     *
     * @param nums
     * @param l
     * @param mid
     * @param r
     */
    private void mergeOfTwoSortedArrAndCountSmaller(int[] nums, int l, int mid, int r) {
        // 3,4  1,2
        for (int i = l; i <= r; i++) {
            temp[i] = indexes[i];
        }
        int i = l;
        int j = mid + 1;
        // 左边出列的时候，计数
        for (int k = l; k <= r; k++) {
            if (i > mid) {
                indexes[k] = temp[j];
                j++;
            } else if (j > r) {
                indexes[k] = temp[i];
                i++;
                // 此时 j 用完了，[7,8,9 | 1,2,3]
                // 之前的数就和后面的区间长度构成逆序
                counter[indexes[k]] += (r - mid);
            } else if (nums[temp[i]] <= nums[temp[j]]) {
                indexes[k] = temp[i];
                i++;
                // 此时 [4,5, 6   | 1,2,3 10 12 13]
                //           mid          j
                counter[indexes[k]] += (j - mid - 1);
            } else {
                // nums[indexes[i]] > nums[indexes[j]] 构成逆序
                indexes[k] = temp[j];
                j++;
            }
        }
    }

    public static void main(String[] args) {
        int[] nums = new int[]{5, 2, 6, 1};
        Solution solution = new Solution();
        List<Integer> countSmaller = solution.countSmaller(nums);
        System.out.println(countSmaller);
    }
}
```

**复杂度分析：**

+ 时间复杂度：$O(N \log N)$，数组的元素个数是 $N$，递归执行分治法，时间复杂度是对数级别的，因此时间复杂度是 $O(N \log N)$。
+ 空间复杂度：$O(N)$，需要 $3$ 个数组，一个索引数组，一个临时数组用于索引数组的归并，还有一个结果数组，它们的长度都是 $N$，故空间复杂度是 $O(N)$。

这道题还可以使用树状数组求解，这一点我们以后再介绍。

