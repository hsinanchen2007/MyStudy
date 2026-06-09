### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        '''
        dict,res = {},0
        for i in nums:
            dict[i] = dict.get(i,0)+1
        if k<0: return 0
        elif k==0:
            values = dict.values()
            for k in values:
                if i>=2:
                    res+=1
        else:
            for i in set(nums):
                if dict.get(i+k):
                    res+=1
        return res
        '''
        dict,res={},0
        for i in nums:
            dict[i] = dict.get(i,0)+1
        nums.sort()
        if k==0:
            for i in nums:
                if dict[i]!=1:
                    res+=1
                    dict[i]=1
        else:
            for j in nums:
                if dict[j]!=0:
                    if dict.get(j+k):
                        res+=1
                dict[j]=0
        return res
```