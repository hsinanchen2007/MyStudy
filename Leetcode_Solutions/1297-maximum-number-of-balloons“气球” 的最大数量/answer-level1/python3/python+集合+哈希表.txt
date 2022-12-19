![image.png](https://pic.leetcode-cn.com/59e85203ab00a89727045e6ae9b7107415e937ac62bc249ee399df1a72ff58c1-image.png)
```
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        balloon = 'balloon'
        d ={}
        for i in text:
            if i in balloon:
                if i in d:
                    d[i] += 1
                else:
                    d[i] = 1
            continue
        if len(d) != len(set(balloon)):
            return 0
        return min(min(d.values()),d['l']//2,d['o']//2)

```
