### 解题思路
我真是个笨比

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dic1={nums[0]:0}
        for i in range(len(nums)):
          k=0
          for j in list(dic1.keys()):
            if j==nums[i]:
                dic1[j]+=1
                k=1
          if k!=1:
             dic1[nums[i]]=1
             k=0
        return max(dic1,key=dic1.get)
```