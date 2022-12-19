### 解题思路
1. 首先先求出数字相同位置相同的个数。
2. 求数字相同但位置不同的个数之前要把之前的位置相同的删除掉再统计。
3. 求出数字相同但位置不同的个数。

### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        count_s = collections.Counter(secret)
        count_g = collections.Counter(guess)

        a_count, b_count = 0, 0
        # 求相同位置的个数
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                a_count += 1
                # 删除掉刚刚已经统计过的相同数值相同位置的数。
                count_s[secret[i]] -= 1
                count_g[guess[i]] -= 1
        
        # 求数字相同但位置不同的个数
        for k in count_g & count_s:
            b_count += min(count_s[k], count_g[k])
        
        return str(a_count)+'A'+ str(b_count)+'B'
```