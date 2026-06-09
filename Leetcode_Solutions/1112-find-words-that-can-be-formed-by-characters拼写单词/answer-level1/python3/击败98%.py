### 解题思路
采用collection.Counter()太过耗时，故寻找新的解决方案。

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        length=0
        for item in words:
            for char in item:
                if item.count(char)>chars.count(char):
                    break
            else:  #for ... else ... 结构是关键点
                length+=len(item)        
        return length

```