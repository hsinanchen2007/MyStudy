### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compress(self, chars: List[str]) -> int:
        n = 0
        r = 1
        p = 0
        i = 0
        n = 0
        flag = 0
        while(i < len(chars)):
            if i == len(chars) - 1:
                chars[n] = chars[i]
                n = n + 1
            for j in range(i+1,len(chars)):
                p = j
                if chars[i] == chars[j]:
                    if j == len(chars) - 1:
                        if j - i + 1 < 10:
                            chars[n] = chars[i]
                            chars[n + 1] = str(j - i + 1)
                            flag = 1
                            i = p - 1
                            n = n + 2
                            break
                        else:
                            chars[n] = chars[i]
                            chars[n + 1] = str(int((j - i + 1) / 10))
                            chars[n + 2] = str((j - i + 1) % 10)
                            flag = 1
                            i = p - 1
                            n = n + 3
                            break
                    continue
                if chars[i] != chars[j] and j != i + 1:
                    if j - (i + 1) + 1 < 10:
                        chars[n] = chars[i]
                        chars[n + 1] = str(j - (i + 1) + 1)
                        i = p - 1
                        n = n + 2
                        break
                    else:
                        chars[n] = chars[i]
                        chars[n + 1] = str(int((j - (i + 1) + 1) / 10))
                        chars[n + 2] = str((j - (i + 1) + 1) % 10)
                        i = p - 1
                        n = n + 3
                        break
                if chars[i] != chars[j] and j == i + 1:
                    chars[n] = chars[i]
                    i = p - 1
                    n = n + 1
                    break
            i = i + 1
            if flag == 1:
                break
        
        r = n
        return r
```