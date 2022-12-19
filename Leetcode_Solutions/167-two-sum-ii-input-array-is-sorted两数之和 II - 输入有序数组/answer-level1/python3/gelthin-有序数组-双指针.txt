### 解题思路
#### 双指针解法
对于有序数组，可以使用双指针进行求解 nums[i]+nums[j]

#### hash表解法
hash 表需要额外 O(n) 空间，且未利用到数组已经排好序的特性，与 [1. 两数之和](https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-2/) 解法相同


#### 二分解法
从头开始遍历数组中元素，设为 x, 则可以用二分查找检查是否在数组中存在另一个数 target-x，如果存在则成功。如果不存在，则测试下一个元素。但这个效率很低，O(n*logn,), 还不如用第一题的 Hash 表解法 O(n)，不过Hash表需要额外 O(n) 的空间。

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        i, j = 0, n-1
        while(i<=j):
            if target == numbers[i] + numbers[j]:
                return [i+1, j+1]
            elif numbers[i] + numbers[j] < target:
                i += 1
            else:
                j -= 1

```