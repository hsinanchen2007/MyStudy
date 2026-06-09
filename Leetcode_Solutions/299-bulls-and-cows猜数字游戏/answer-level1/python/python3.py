### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        a = 0
        b = 0
        secret = list(secret)
        guess = list(guess)
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                secret[i] = guess[i] = -1
                a += 1
        while -1 in secret:
            secret.remove(-1)
            guess.remove(-1)
        for j in range(len(secret)):
            if secret[j] in guess:
                guess.remove(secret[j])
                b += 1
        return (str("%dA%dB" % (a, b)))
        #         for k in range(len(ls)):
        #             if ls[k] == guess[i]:
        #                 ls.pop(k)
        #                 break
        #         a += 1
        #     if secret[i] != guess[i] and guess[i] in ls:
        #         for j in range(len(ls)):
        #             if ls[j] == guess[i]:
        #                 ls.pop(j)
        #                 break
        #         b += 1
        # return (str("%dA%dB" % (a, b)))
```