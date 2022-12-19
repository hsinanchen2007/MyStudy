```
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        from collections import Counter
        if not s or not words: return []
        w_num = len(words)  # 单词的个数
        w_len = len(words[0])  # 单词的长度
        res = []  # 记录结果
        for i in range(len(s)-w_num*w_len+1):
            temp_s = s[i:i+w_num*w_len]
            temp_sl = [temp_s[i:i+w_len] for i in range(0, len(temp_s), w_len)]  # 按照单词的长度切割字符串
            if Counter(words) == Counter(temp_sl):
                res.append(i)
        return res

```
