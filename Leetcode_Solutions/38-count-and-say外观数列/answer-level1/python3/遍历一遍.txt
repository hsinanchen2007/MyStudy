### 解题思路
切片为111 22 11 2 11这种形式（连续相同数字构成单独的子序列），然后进行描述
拿一个具体的例子（如1221）模拟即可

### 代码

```python3
class Solution:
    def __init__(self):
        self.a = 3
    def countAndSay(self, n: int) -> str:
        '''
        思路：
        切片为111 22 11 2 11这种形式（连续相同数字构成单独的子序列），然后进行描述
        '''
        # print(self.a)  不可行，否则可以一次把res[0]至res[29]全部求出，然后每次直接返回res[i-1]
        res = ["1"] * 30
        for i in range(1, n):
            j = 0
            l = len(res[i-1])
            s = ''
            while j < l:
                count = 0
                start = True
                while j < l and (start or res[i-1][j] == res[i-1][j-1]):
                    j += 1
                    count += 1
                    start = False
                s = s + str(count) + str(res[i-1][j-1])
            res[i] = s
            # print(s)

        return res[n - 1]

        
```