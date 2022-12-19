### 解题思路

对输入字符串遍历一次，计算A的个数和各个数字出现的次数；再对字典遍历一次，计算B的个数。
### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        s_dict = {'0':0, '1':0, '2':0, '3':0, '4':0, '5':0, '6':0, '7':0, '8':0, '9':0}
        g_dict = {'0':0, '1':0, '2':0, '3':0, '4':0, '5':0, '6':0, '7':0, '8':0, '9':0}

        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            s_dict[secret[i]] += 1
            g_dict[guess[i]] += 1

        cows = sum(min(s_dict[str(i)], g_dict[str(i)]) for i in range(10)) - bulls

        return '{bulls}A{cows}B'.format(bulls = bulls, cows = cows)
```