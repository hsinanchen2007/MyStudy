### 解题思路
暴力解法，线性遍历，时间复杂度O(n)

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        #设置初始res，如果下面找不到则返回初始值
        res = [-1, -1]
        # 从左到右遍历得到左区间
        for i in range(len(nums)):
            if nums[i] == target:
                res[0] = i
                break
        # 从右到左遍历得到右区间
        # 倒序循环range(start, end, step) end是不包括的
        for j in range(len(nums)-1, -1, -1): 
            if nums[j] == target:
                res[1] = j
                break

        return res
        
```