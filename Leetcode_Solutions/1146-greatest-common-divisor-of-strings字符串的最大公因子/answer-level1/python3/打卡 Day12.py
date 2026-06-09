
### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:

        lens1 = len(str1)
        lens2 = len(str2)
        tmp = ''
        ans = ''
        for i,e in enumerate(str2):
            tmp += e
            if lens1%(i+1) == 0 and tmp * (lens1//(i+1)) == str1 and \
                    lens2%(i+1) == 0 and tmp * (lens2//(i+1)) == str2 :
                ans = tmp
        return ans
```