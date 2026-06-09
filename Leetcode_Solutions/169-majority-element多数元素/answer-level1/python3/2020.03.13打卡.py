### 解题思路
推理得，排序后，奇数个元素中位数为多数元素，偶数个元素中位数上下0.5的位置也为多数元素，找到多数元素存在的位置，输出对应的元素即可。

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        loc = len(nums) // 2
        return nums[loc]
```