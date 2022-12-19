### 解题思路
可以用排序再判断 O(nlogn)
用额外的哈希表 O(n), O(n)
用自身作为哈希

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for i, value in enumerate(nums):
            // 若数值已经在对的位置则不变
            while i != value:
                // 如果值在哈希位置不相同，则归到正确位置
                if nums[value] != value:
                    nums[i], nums[value] = nums[value], nums[i]
                # 相同则判断错误
                else:
                    return value
        return -1
```