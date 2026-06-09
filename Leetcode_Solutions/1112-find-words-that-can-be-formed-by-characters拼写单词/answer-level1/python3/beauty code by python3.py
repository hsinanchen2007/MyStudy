### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        lenth = 0
        dictionary = {}
        for char in chars:
            dictionary[char] = dictionary.setdefault(char, 0) + 1
        for word in words:
            tdictionary = dictionary.copy() 
            for char in word:
                if char not in tdictionary.keys() or tdictionary[char] == 0:
                    break
                else:
                    tdictionary[char] -= 1
            else:        
                lenth += len(word)
        return lenth
```