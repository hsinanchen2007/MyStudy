## 思路:

假设$nums = [x_1, x_2, x_3, ..., x_n]$，我们令数组最后变成相等的数为$x$，求$|x - x_1| + |x - x_2| + ... + |x - x_n|$的最小值，通过几何关系，`x = 中位数`即可：

![image-20200406192332033.png](https://pic.leetcode-cn.com/dadc96fcd3dff11df807b1b7134513afe313b8ef0c0f0b5bc0a222f5e877eedc-image-20200406192332033.png)




这里有详细解释：https://www.sohu.com/a/226264278_553401

所以，排序找中位数

思路一：直接库函数排序

思路二：快排找中位数，时间复杂度$O(n)$，（python超时， python的复杂度搞不清楚的）

## 代码:

思路一：

```python
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        med = sorted(nums)[len(nums)//2]
        return sum(abs(num - med) for num in nums)
```

思路二：快排（超时， python的复杂度搞不清楚的）

```python
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        

        def partition(left, right):
            pivotValue = nums[right]
            i = left
            for j in range(left, right + 1):
                if nums[j] < pivotValue:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
            nums[i], nums[right] = nums[right], nums[i]
            return i

        def quicksort(left, right, k):
            if left == right: return nums[left]
            pivotIndex = partition(left, right)
            if pivotIndex == k:
                return nums[k]
            elif pivotIndex > k:
                return quicksort(left, pivotIndex - 1, k)
            else:
                return quicksort(pivotIndex + 1, right, k)

        med = quicksort(0, len(nums) - 1, len(nums)//2)
        return sum(abs(num - med) for num in nums)
```

