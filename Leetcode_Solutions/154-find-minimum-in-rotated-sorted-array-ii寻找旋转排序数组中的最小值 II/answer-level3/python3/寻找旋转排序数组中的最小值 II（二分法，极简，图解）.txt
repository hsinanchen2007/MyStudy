#### 思路：

- 旋转排序数组 $nums$ 可以被拆分为 2 个排序数组 $nums1$ , $nums2$ ，并且 `nums1任一元素 >= nums2任一元素`；因此，考虑二分法寻找此两数组的分界点 $nums[i]$ (即第 2 个数组的首个元素)。
- 设置 $left$, $right$ 指针在 $nums$ 数组两端，$mid$ 为每次二分的中点：
  - 当 `nums[mid] > nums[right]`时，$mid$ 一定在第 1 个排序数组中，$i$ 一定满足 `mid < i <= right`，因此执行 `left = mid + 1`；
  - 当 `nums[mid] < nums[right]` 时，$mid$ 一定在第 2 个排序数组中，$i$ 一定满足 `left < i <= mid`，因此执行 `right = mid`；
  - 当 `nums[mid] == nums[right]` 时，是此题对比 **[153题](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/find-minimum-in-rotated-sorted-array-er-fen-fa-by-/)** 的难点（原因是此题中数组的元素**可重复**，难以判断分界点 $i$ 指针区间）；
    - 例如 $[1, 0, 1, 1, 1]$ 和 $[1, 1, 1, 0, 1]$ ，在 `left = 0`, `right = 4`, `mid = 2` 时，无法判断 $mid$ 在哪个排序数组中。
    - 我们采用 `right = right - 1` 解决此问题，证明：
        1. 此操作*不会使数组越界*：因为迭代条件保证了 `right > left >= 0`；
        2. 此操作*不会使最小值丢失*：假设 $nums[right]$ 是最小值，有两种情况：
            - 若 $nums[right]$ 是唯一最小值：那就不可能满足判断条件 `nums[mid] == nums[right]`，因为 `mid < right`（`left != right` 且 `mid = (left + right) // 2` 向下取整）；
            - 若 $nums[right]$ 不是唯一最小值，由于 `mid < right` 而 `nums[mid] == nums[right]`，即还有最小值存在于 $[left, right - 1]$ 区间，因此不会丢失最小值。
- 以上是理论分析，可以代入以下数组辅助思考：
  - $[1, 2, 3]$
  - $[1, 1, 0, 1]$
  - $[1, 0, 1, 1, 1]$
  - $[1, 1, 1, 1]$
- 时间复杂度 $O(logN)$，在特例情况下会退化到 $O(N)$（例如 $[1, 1, 1, 1]$）。

#### 图解：

<![Picture1.png](https://pic.leetcode-cn.com/5c4b7d4827e1538ca8f5a67f2c64705304ae985f80bd1e43d6f193bd2f2dea57-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/8bdaadfe391de9f71029d8993d0b0befc63cf89d9d79ad821eb1508532ac4e9c-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/158047037b8a79d0a8afdb25025665658286548055c95c0feffea67ccf0a6133-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/d5b3ce02860dd88525abb972eaf49d8a0484f402e7a50739fced16174256f8ad-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/ea7cca7c83afd8a5423e2e16a684fd5300301e957b79134418d8087f2eba8e0b-Picture5.png)>


#### 代码：

```Python []
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right]: left = mid + 1
            elif nums[mid] < nums[right]: right = mid
            else: right = right - 1 # key
        return nums[left]
```
```Java []
class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else right = right - 1;
        }
        return nums[left];
    }
}
```