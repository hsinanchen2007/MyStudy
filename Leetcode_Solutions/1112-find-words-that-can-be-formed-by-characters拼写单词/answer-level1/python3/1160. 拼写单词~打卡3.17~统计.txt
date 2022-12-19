### 解题思路
这道题使用统计的方法，使用字典记录words中每个单词中字符出现的次数， 以及记录chars中字符出现的次数（这样就能保证每个单词只能用一次）
如果words中的单词都出现在了chars中，且出现次数小于等于chars中出现的，那么计入结果即可

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        from collections import defaultdict

        chars_dict = defaultdict(int)
        for c in chars:
            chars_dict[c] = chars_dict.get(c, 0) + 1
        
        def help(word):
            word_dict = defaultdict(int)
            for w in word:
                word_dict[w] = word_dict.get(w, 0) + 1
            return word_dict
        
        ans = 0
        for word in words:
            word_dict = help(word)
            temp = 0
            for c, time  in word_dict.items():
                if c in word_dict and time <= chars_dict[c]:
                    temp += time
                else:
                    temp = 0
                    break
            print(temp)
            ans += temp
        
        return ans

        
```