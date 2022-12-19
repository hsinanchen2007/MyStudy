### 解题思路
这凭啥也是medium

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        res={}
        for num in nums :
            if num not in res :
                res[num]=1 
            else :
                res[num]+=1
        dst=[]
        for key in res:
            if res[key]>len(nums)/3 :
                dst+=[key]
        return dst
                

```