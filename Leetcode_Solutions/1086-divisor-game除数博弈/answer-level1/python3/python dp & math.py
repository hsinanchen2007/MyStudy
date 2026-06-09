### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def divisorGame(self, N: int) -> bool:
        '''
        return N%2==0
        '''

        res = [False for i in range(N+2)]
        res[1] = False
        for i in range(2,N+1):
            tmp = False
            for j in range(1,i//2+1):
                if i%j==0:
                    if not res[i-j]:
                        tmp = True
                        break
            res[i]=tmp
        return res[N]
```