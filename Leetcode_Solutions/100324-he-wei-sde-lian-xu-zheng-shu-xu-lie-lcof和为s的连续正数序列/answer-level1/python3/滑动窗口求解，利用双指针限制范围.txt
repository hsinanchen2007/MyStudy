### 解题思路
滑动窗口求解，利用双指针限制范围，详见代码

### 代码

```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res=[]
        l=1
        r=2
        total=3
        while l<r:
            if total==target:
                res.append(list(range(l,r+1)))
                total-=l
                l+=1
            elif total<target:
                r+=1
                total+=r
            else:
                total-=l
                l+=1
        return res
```

