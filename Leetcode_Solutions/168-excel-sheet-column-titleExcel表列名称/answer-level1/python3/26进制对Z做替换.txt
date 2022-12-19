执行用时 :32 ms, 在所有 python3 提交中击败了91.46%的用户
内存消耗 :12.6 MB, 在所有 python3 提交中击败了99.13%的用户

### 代码

```python3
class Solution:
    def convertToTitle(self, n: int) -> str:
        s = ''
        while n > 0:
            if n%26==0:
                s+='Z'
            else:
                s+=chr(n%26+64)
            n = (n-ord(s[-1])+64)//26
            print(n)
        return s[::-1]
```