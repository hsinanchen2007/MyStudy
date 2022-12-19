### 解题思路
![image.png](https://pic.leetcode-cn.com/05f55607704465c60ba8dd61e6dbc100994f5feb5789581f81cc901e2441ed0e-image.png)

贪心算法，加入最多的字符。如果会构成三个连续，则加入次多的算符。

### 代码

```python3
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        m = {'a':a, 'b':b, 'c':c}
        re = ''
        while True:
            tmp = sorted([(k, v) for k, v in m.items()], key = lambda x:x[1], reverse = True)
            if len(re)>=2 and re[-1] == re[-2] and re[-1] == tmp[0][0]:
                if m[tmp[1][0]] <=0:
                    break
                re += tmp[1][0]
                m[tmp[1][0]] -= 1
            else:
                if m[tmp[0][0]] <= 0:
                    break
                re += tmp[0][0]
                m[tmp[0][0]] -= 1
        return re
```