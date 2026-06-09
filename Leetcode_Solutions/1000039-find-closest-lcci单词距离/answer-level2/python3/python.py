### 解题思路
首先找出word1与word2的所有索引，然后找出索引最小的差值

### 代码

```python3
class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        id1 = [i for i,word in enumerate(words) if word ==word1]
        id2 = [i for i,word in enumerate(words) if word ==word2]
        min_len = len(words)
        for ele1 in id1:
            for ele2 in id2:
                a = abs(ele1-ele2)
                if a< min_len:
                    min_len = a
        return min_len
            
```