### 解题思路
两种方法，思路差不多

方法一：更新区间边界

### 代码

```python3
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 0: return []

        res = []
        tmp = [nums[0]]
        for n in nums[1:]:
            if n-1 == tmp[-1]:
                tmp = [tmp[0]] + [n] if len(tmp) == 2 else tmp + [n]
            else:
                res += [str(tmp[0])+'->'+str(tmp[1])] if len(tmp) == 2 else [str(tmp[0])]
                tmp = [n]
        res += [str(tmp[0])+'->'+str(tmp[1])] if len(tmp) == 2 else [str(tmp[0])]

        return res

```


### 解题思路

方法二：用双指针

### 代码

```python3
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 0: return []

        res = []
        tmp = [nums[0]]
        for n in nums[1:]:
            if n-1 == tmp[-1]:
                tmp = [tmp[0]] + [n] if len(tmp) == 2 else tmp + [n]
            else:
                res += [str(tmp[0])+'->'+str(tmp[1])] if len(tmp) == 2 else [str(tmp[0])]
                tmp = [n]
        res += [str(tmp[0])+'->'+str(tmp[1])] if len(tmp) == 2 else [str(tmp[0])]

        return res

```