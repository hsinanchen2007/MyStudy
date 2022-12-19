### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        nums.sort()
        a=0
        Max=0
        try :
            if nums[-2]>=0:
                pass
        except IndexError:
            return 0
        else: 
            for i in range(len(nums)-1):
                a=nums[i+1]-nums[i]
                if Max<a:
                    Max=a
        return Max

```