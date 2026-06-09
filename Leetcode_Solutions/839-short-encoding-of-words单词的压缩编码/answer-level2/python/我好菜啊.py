### 解题思路
就是把每个字符串倒过来用re匹配

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words) -> int:
        for i in range(len(words)):
            words[i] = words[i][::-1]
        words = sorted(words)
        res = 0
        for i in range(len(words) -1):
            j = i + 1
            flag = False
            while j < len(words) and words[j][0] == words[i][0]:
                if re.match(words[i], words[j]):
                    flag = True
                    break
                j += 1
            if not flag:
                res += len(words[i]) + 1

        return res + len(words[-1]) + 1


```