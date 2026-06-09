### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def confusingNumberII(self, N: int) -> int:
        digits = [0,1,6,8,9]
        n = len(digits)
        self.count = 0
        def backtrack(N,cur):
            for i in range(n):
                new = cur*10 + digits[i]
                if 0<new<=N: 
                    if confusingNumber(new):
                        self.count+=1
                    backtrack(N,new)



        def confusingNumber(N):        
            N = str(N)
            change = {
                '0': '0',
                '1': '1',
                '6': '9',
                '8': '8',
                '9': '6'
            }
            M = ''
            for x in N:
                if x not in change:
                    return False
                M += change[x]
            return ''.join(reversed(N)) != M
        
        backtrack(N,0)
        return self.count
```