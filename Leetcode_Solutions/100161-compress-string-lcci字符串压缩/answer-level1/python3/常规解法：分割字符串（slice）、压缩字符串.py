### 解题思路
时间复杂度：O(n)
空间复杂度：O(n)

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        # 特殊情况处理
        if len(S)<=2: 
            return S
        
        length = len(S)
        l = list()
        tag = 0
        # 切割字符串
        for i in range(0, length - 1):
            if S[i] == S[i + 1]:
                tag += 1
            elif S[i] != S[i + 1]:
                l.append(S[i - tag:i + 1])
                tag = 0
            if (i + 1) == (length - 1):
                l.append(S[i - tag + 1:])

        # 压缩字符串
        pres_str=''
        for item in l:
            s = item[0]
            num = len(item)
            s += str(num)
            pres_str+=s

        # 返回压缩后的字符串
        return S if len(pres_str)>=length else pres_str
```