### 解题思路
三种写法~

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        from collections import Counter
        # dic = {}
        # for char in chars:
        #     dic[char] = dic.get(char, 0) + 1
        dic = Counter(chars)

        res = 0
        for word in words:
            word_dic = Counter(word)
            if all([0,1][word_dic[w] <= dic.get(w, 0)] for w in word_dic):
            # if all((word_dic[w] <= dic.get(w, 0) and 1 or 0) for w in word_dic):
            # for w in word_dic:
            #     if word_dic[w] > dic.get(w, 0):
            #         break
            # else:
                res += len(word)
        return res


```