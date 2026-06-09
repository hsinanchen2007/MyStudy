### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def divisorGame(self, N: int) -> bool:
        '''
        奇则输，偶则赢
        return N%2==0
        '''
        target = [0 for i in range(N+1)]
        target[1] = 0
        if N<=1: return False
        else:
            target[2]=1
            for i in range(3,N+1):
                for j in range(1,i//2):
                    if i%j==0 and target[i-j]==0:
                        target[i] = 1
                        break
            return target[N]==1
```