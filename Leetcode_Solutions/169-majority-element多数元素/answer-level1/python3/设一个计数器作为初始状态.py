### 解题思路
c=0时为初始状态，每次回到初始状态就重新计数，设res为众数

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        c=0
        for i in nums:
            if c==0:
                res=i
            if res==i:
                c+=1
            else:
                c-=1
        return res
```