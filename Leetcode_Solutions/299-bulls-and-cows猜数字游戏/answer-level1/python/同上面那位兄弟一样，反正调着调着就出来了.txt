### 解题思路


### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        cows = 0
        bull_dict = {}
        for i in secret:
            if i not in bull_dict.keys():
                bull_dict[i] = 1
            else:
                bull_dict[i] += 1
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
                bull_dict[guess[i]] -= 1
        for i in range(len(secret)):
            if secret[i] != guess[i] and guess[i] in secret and bull_dict[guess[i]] != 0:
                cows += 1
                bull_dict[guess[i]] -= 1
        return str(bulls) + "A" + str(cows) + "B"

```