### 解题思路
思想是：ip四段，确定第一段，然后二段，三段、四段随机匹配，每一次判断都要判其是否合法ip段，最后用result拼接结果

### 代码

```python3
class Solution:

    def restoreIpAddresses(self, s: str):
        def isNum(num):
            if num.isdigit() and 0<=int(num)<=255 and str(int(num)) == num:
                return True
            return False

        result = []
        # 复原IP地址
        if not s.isdigit() or  4 > len(s) or 12 < len(s):
            return result
        
        for i in range(1,4):
            w1 = s[:i]
            if not isNum(w1):
                continue
            for j in range(i+1,i+4):
                w2 = s[i:j]
                if not isNum(w2):
                    continue
                for k in range(j+1,j+4):
                    w3 = s[j:k]
                    w4 = s[k:]
                    if not isNum(w3) or not isNum(w4):
                        continue
                    result.append(w1 + "." + w2 + "." + w3 + "." + w4)
        return result
```