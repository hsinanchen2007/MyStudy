### 解题思路
一开始想到用collection，但是不会
先排序，然后双指针，结果中间的判断搞死我了

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        s_chars = sorted (chars)
        l_char = len(chars)
        #res = []
        res = 0
        for word in words:
            s_word = sorted(word)
            l_word=len(word)
            if l_word>l_char:
                continue
            c_p = 0
            all_judge = 1
            for k in range(l_word):
                judge = 0
                for i in range(c_p,l_char):
                    if s_chars[i]==s_word[k]:
                        judge = 1
                        break
                if judge == 0:
                    all_judge = 0
                    break
                c_p = i+1
                if c_p > l_char-1:
                    break
                if all_judge == 0:
                    break
            if k != l_word-1:
                all_judge=0

            if all_judge:
                #res.append(word)
                res = res + l_word
        return res

            
```