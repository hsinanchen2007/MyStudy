### 解题思路
常规解法的反应用，从后往前进行遍历，运算时间几乎是原先正向的1/4.仅供娱乐吧。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lens = len(nums)
        j=-1
        for i in range(-2,-lens-1,-1):
            temp=nums[i+1:]
            if target-nums[i] in temp:
                j=temp.index(target-nums[i])
            if j>=0:
                return [lens+i,lens+i+j+1]
```