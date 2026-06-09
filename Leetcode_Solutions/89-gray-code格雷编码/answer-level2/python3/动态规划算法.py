### 解题思路

### 代码

```python3
class Solution:
    def grayCode(self, n: int) -> List[int]:
        grayArray=[[0]]
        for i in range(1,n+1):
            grayArray.append([])
        for i in range(1,n+1):
            count=1<<i
            for j in range(count):
                if j<count/2:
                    grayArray[i].append(grayArray[i-1][j])
                else:
                    temp=1<<i-1
                    grayArray[i].append(grayArray[i][count-1-j]+temp)
        return grayArray[n]
            
```