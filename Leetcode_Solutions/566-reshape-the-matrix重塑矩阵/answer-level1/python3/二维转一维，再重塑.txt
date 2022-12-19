### 解题思路
将二维数组转化为一维数组，然后判断是否新旧元素个数相等。相等的话就双循环重塑，不等就返回原数组。
缺点：这种方法在大数组的情况下可能会耗很多时间。但是对于本题足够了。

### 代码

```python3
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        num=[]
        for n in nums:
            num.extend(n)
        lens=len(num)
        if r*c==lens:
            temp=[]
            nu=[]
            i=0
            for k in range(r):
                for j in range(c):
                    temp.append(num[i])
                    i+=1
                nu.append(temp)
                temp=[]
            return nu
        else:
            return nums
```