**思路一:** 和 [1. 两数之和](https://leetcode-cn.com/problems/two-sum/) | [题解链接](https://leetcode-cn.com/problems/two-sum/solution/ha-xi-zi-dian-kuai-su-cha-zhao-by-powcai)一样!使用 字典解决! 时间复杂度也是 $O(n)$

**思路二:** 双指针

因为是有序数组,  用一头一尾两个指针移动调整使它之和接近 `target`

时间复杂度: $O(n)$

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        while left < right:
            total = numbers[left] + numbers[right]
            if total == target:
                return [left + 1, right + 1]
            elif total > target:
                right -= 1
            else:
                left += 1
```

**思路三:** 二分搜索

固定一个数`num`, 用二分搜索找`target - num ` 

时间复杂度: $O(nlogn)$

```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        for i in range(n - 1):
            num = target - numbers[i]
            idx = bisect.bisect_left(numbers, num, i + 1, n)
            if idx < n and numbers[idx] == num:
                return [i + 1, idx + 1]
```

