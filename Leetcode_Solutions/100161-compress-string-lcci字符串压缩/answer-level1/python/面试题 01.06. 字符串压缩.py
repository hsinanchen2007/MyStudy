### 解题思路
入门题，直接写就可以了。
还有一种思路是利用双指针，看起来会更加工整。


### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if len(S) == 0:
            return S
        ret = S[0]
        count = 1

        for i in range(1, len(S)):
            if S[i] == ret[-1]:
                count += 1
            else:
                ret += str(count) + S[i]
                count = 1
        
        ret += str(count)

        if len(ret) < len(S):
            return ret
        else:
            return S 
```