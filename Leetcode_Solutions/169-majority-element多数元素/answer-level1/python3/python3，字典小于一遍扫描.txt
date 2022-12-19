### 解题思路
使用字典保存出现次数
一旦某个key出现次数达标，就输出

### 代码

```python3
import math
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums)==0:
            return None
        adic={}
        for i in nums:
            if i in adic.keys():
                adic[i]+=1
                if adic[i]>math.floor(len(nums)/2):
                    return i
            else:
                adic[i]=1
                if adic[i]>math.floor(len(nums)/2):
                    return i
```