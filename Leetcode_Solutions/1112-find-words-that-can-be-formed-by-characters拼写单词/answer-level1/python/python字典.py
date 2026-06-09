### 解题思路
对字母表和每个单词分别创建字典，比较每个字母出现的次数。

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        dic = {}
        res = 0
        for char in chars:
            dic[char] = dic.get(char,0) + 1
        for word in words:
            w_dic = {}
            for w in word:
                w_dic[w] = w_dic.get(w,0) + 1
            count = 0
            for w in word:
                if w_dic[w] <= dic.get(w,0):#此处注意字母表中可能不包含单词里的所有字母
                    count += 1
                else:
                    break
                if count == len(word):
                    res += len(word)
        return res
                
```