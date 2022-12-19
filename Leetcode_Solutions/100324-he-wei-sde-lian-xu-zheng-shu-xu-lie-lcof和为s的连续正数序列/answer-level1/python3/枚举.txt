### 解题思路
在[2,(2*target)**0.5)]范围内枚举解数组长度即可

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans = []
        for i in range(int((2*target)**0.5)+1,1,-1):
            if target%i==0 and i&1==1:
                star = target/i-(i-1)/2
                if star==0:continue
                tmp = []
                for j in range(int(star),int(star+i)):
                    tmp.append(j)
                ans.append(tmp)
            if target/i-target//i==0.5:
                star = target//i-i/2+1
                if star==0:continue
                tmp = []
                for j in range(int(star), int(star + i)):
                    tmp.append(j)
                ans.append(tmp)
        
        return ans
```