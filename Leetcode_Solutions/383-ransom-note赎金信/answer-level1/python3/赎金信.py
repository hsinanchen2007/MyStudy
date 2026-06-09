### 解题思路
一、collections.Counter解法，一行代码解决，参考大佬的。
[collections.Counter()](collections.Counter())
### 代码

```python3
import collections
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        return collections.Counter(magazine) & collections.Counter(ransomNote) == collections.Counter(ransomNote)

```
二、本办法，在magazine中依次查找ransom中的每一个字符。

```
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransomNote = list(ransomNote)
        magazine = list(magazine)
        for char in ransomNote:
            if char not in magazine:
                return False
            if char in magazine:
                magazine.pop(magazine.index(char))
        return True
```