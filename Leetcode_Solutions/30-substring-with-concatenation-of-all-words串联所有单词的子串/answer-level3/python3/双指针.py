### 解题思路
问题是个双指针的问题，但是要根据规则考虑一些case；


### 代码

```python
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words:
            return []
        l_each_word = len(words[0])
        l_tot = len(s)
        res = []
        for start_ind in range(l_each_word):
            st = start_ind
            ed = start_ind
            candi_words = [iword for iword in words] # deep copy!
            while ed < l_tot:
                # print(st, ed, res, candi_words)
                cur_word = s[ed: ed+l_each_word]
                ed += l_each_word
                if cur_word not in words:
                    st = ed
                    candi_words = [iword for iword in words]
                else:
                    if cur_word in candi_words:
                        candi_ind = candi_words.index(cur_word)
                        del candi_words[candi_ind]
                        if not candi_words:
                            res.append(st)
                    else:
                        while cur_word not in candi_words:
                            f_word = s[st:st+l_each_word]
                            assert f_word in words
                            candi_words.append(f_word)
                            st += l_each_word
                        candi_words.pop()
                        if not candi_words:
                            res.append(st)
        return res
```