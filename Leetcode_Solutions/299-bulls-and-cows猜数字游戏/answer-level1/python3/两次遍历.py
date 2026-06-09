### 解题思路
虽然简单，但是还是提交了很多次！

### 代码

```python3
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        if not secret or not guess:
            return "0A0B"

        A=0
        B=0

        d={}

        for i in range(len(guess)):
            if guess[i]==secret[i]:
                A+=1
            else:
                d[secret[i]]=d.get(secret[i], 0)+1

                
        for i in range(len(guess)):
            if guess[i]!=secret[i]:
                if guess[i] in d and d[guess[i]]>0:
                    B+=1
                    d[guess[i]]-=1
        return str(A)+"A"+str(B)+"B"


```