### 解题思路
此题有多种不同思路
+ 排序后查看相邻位置的元素
+ 使用 hash 表，记录一个元素是否出现过。 在python 3 中似乎相当于使用 set 以及 dict 等结构，因为这些数据结构就是用 hash 表实现的。 

### 代码

```python3
class Solution:

    def containsDuplicate(self, nums: List[int]) -> bool:
        # hash 表
        set_l = set()
        for x in nums:
            if x in set_l:
                return True
            else:
                set_l.add(x)
        return False
## 解法2
        def containsDuplicate(self, nums: List[int]) -> bool:
            # 排序后处理
            n = len(nums)
            if n <= 1:
                return False
            nums.sort()
            i = 1
            while i<n:
                if nums[i] == nums[i-1]:
                    return True
                i += 1
            return False
```