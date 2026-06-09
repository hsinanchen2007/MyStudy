### 解题思路

### 代码

```python3
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        if not nums:
            return

        d={}
        for num in nums:
            d[num]=d.get(num, 0)+1

        endnum={num:0 for num in nums}
        for num in nums:
            if not d[num]:
                continue
            
            d[num]-=1
            if endnum.get(num-1, 0)>0:
                endnum[num-1]-=1
                endnum[num]+=1
            elif d.get(num+1, 0)>0 and d.get(num+2, 0)>0:
                d[num+1]-=1
                d[num+2]-=1
                endnum[num+2]+=1
            else:
                return False
        return True
```