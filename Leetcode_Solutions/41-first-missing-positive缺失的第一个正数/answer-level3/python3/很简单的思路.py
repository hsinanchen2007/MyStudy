### 解题思路
先排序，得到一个从小到大排序的数组。然后最小正整数是1，传进来的列表都是整数，所以列表中出现1的话，就只能说这个坑被占了,就加1。

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums = sorted(nums)
        max_num = 1
        for i in range(len(nums)):
            if nums[i]==max_num:
                max_num = max_num+1
        return max_num
```