### 解题思路


### 代码

```python3
class Solution:
    def sumZero(self, n: int) -> List[int]:
        res=[0 for i in range(n)]
        l=0
        r=n-1
        while(l<r):
            res[l]=l+5 # 这里可以随便取一个非0整数，不一定是5 （如果是0的话，如果n是奇数，则会在输出的数组中出现3次0）
            res[r]=-l-5
            l+=1
            r-=1
        return res
```