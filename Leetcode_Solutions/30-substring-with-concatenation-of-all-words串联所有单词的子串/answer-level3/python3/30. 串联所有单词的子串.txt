### 解题思路
暴力匹配的方法,时间复杂度为O(n1*n2*n3),n1为字符串的长度，n2为单词个数，n3为每个单词的长度。

### 代码

```python3
class Solution:
    def findSubstring(self, s: str, words):
        if not s or not words:
            return []
        words_num = len(words)
        words_length = len(words[0])
        str_length = len(s)
        if words_num * words_length > str_length:
            return []
        words_read = {}
        res = []
        for i in range(str_length + 1 - words_length * words_num):
            for key in words:
                words_read[key] = 0
            for key in words:
                words_read[key] += 1
            flag = True
            for j in range(i, i + words_length * words_num, words_length):
                if words_read.get(s[j:j + words_length]) == None or words_read[s[j:j + words_length]] == 0:
                    flag = False
                    break
                else:
                    words_read[s[j:j + words_length]] -= 1
            # verify
            if flag:
                res.append(i)
        return res
```