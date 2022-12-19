每个单词都比较一次，然后把符合的地方标记一下，最后更新字符串。
```
class Solution:
    def boldWords(self, words: List[str], S: str) -> str:
        S_result = [0 for x in range(len(S)+2)]
        s_len = len(S)
        for word in words:
            k = len(word)
            for i in range(s_len-k+1):
                temp = S[i:i+k]
                if temp == word:
                    for j in (range(i+1,i+k+1)):
                        S_result[j] = 1
        result = S
        for i in range(s_len,-1,-1):
            if S_result[i]< S_result[i+1]:
                result = result[:i]+'<b>'+result[i:]
            if S_result[i]> S_result[i+1]:
                result = result[:i]+'</b>'+result[i:]
        return result
```
