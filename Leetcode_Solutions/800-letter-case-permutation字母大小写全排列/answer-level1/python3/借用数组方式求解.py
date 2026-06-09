### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        count = 0
        ans = []  
        first = S[0]  #往ans中填充第一个char
        ans.append(first)
        if first.isupper():
            ans.append(first.lower())
        elif first.islower():
            ans.append(first.upper())
        #遍历S
        for i,k in enumerate(S[1:]):
            n = len(ans)
            for _ in range(n):
                tmp = ans.pop(0)
                ans.append(tmp+k)                           
                if k.isupper():
                    ans.append(tmp+k.lower())
                elif k.islower():
                    ans.append(tmp+k.upper())
        return ans
            


```