### 解题思路
时间复杂度较高，击败13.57%

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        length=0
        for item in words:
            if collections.Counter(item)&collections.Counter(chars)==collections.Counter(item):              
                length+=len(item)
        return length

```