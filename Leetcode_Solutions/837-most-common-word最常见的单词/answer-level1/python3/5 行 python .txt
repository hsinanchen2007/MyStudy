### 解题思路
直接原文所有单词小写并正则筛选出所有英文单词，
然后按照从大到小的顺序删选出不在 banned 里的词


### 代码

```python3
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        import re
        word_list = re.findall(u'[a-z]+', paragraph.lower())
    
        from collections import Counter
        for word, _ in Counter(word_list).most_common():
            if word not in banned: return word
```