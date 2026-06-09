### 解题思路
理解清楚题意很重要：
对于每个word，如果能在chars里找到所有的字母，就可认为掌握到了。一对一的关系。
而不是用chars的字母去组成words的众多单词，不是多对一的关系。

思路：
若组成word的每个字母都在chars里，且数量也够，则掌握到了。

两个counter分别记录chars和每个word的字母数量，然后再比较。

时间复杂度：O(所有word长度之和)
空间复杂度：O(26+26)


### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        from collections import Counter
        char_cnt = Counter(chars)
        res = 0
        
        for word in words:
            word_cnt = Counter(word)
            
            if all([char_cnt[w] >= word_cnt[w] for w in word]):
                res += len(word)
            
        return res
```