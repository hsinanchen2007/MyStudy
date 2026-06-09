### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        from collections import Counter
        L = paragraph.replace(',',' ').replace('.','').replace('!','').replace('?','').replace(';','').replace("'",'').lower()

        

        words = L.split()
        
        paragraph = Counter(words).most_common() # 按从大到小的顺序排列
        
        for word in paragraph:
            if word[0] not in banned:
                return word[0]
        return ''
```