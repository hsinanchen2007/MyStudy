### 解题思路
![QQ截图20200304152735.png](https://pic.leetcode-cn.com/8d003801b2a25ec5503660ffb7cb421238ad5a01cb0ce1604891b25671d604da-QQ%E6%88%AA%E5%9B%BE20200304152735.png)

就硬干
### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        sum_A=0
        sum_B=0
        i=0
        for sec,gue in zip(secret,guess):
            if sec==gue:
                sum_A+=1
                guess=guess[0:i]+guess[i+1:]
                secret = secret[0:i] + secret[i + 1:]
                i-=1        
            else:
                pass
            i+=1

        for gue in guess:
            if secret.find(gue)!=-1:
                m=secret.find(gue)
                sum_B+=1
                secret = secret[0:m] + secret[m + 1:]
                if secret=="":
                    break
            else:
                pass
        
        return str(sum_A)+"A"+str(sum_B)+"B"
```