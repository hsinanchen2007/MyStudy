### 解题思路
本质为a，b两个字符串
利用b字符串中的字母组成a
且b中每个字母仅可使用一次

### 代码

```python3
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ran = list(ransomNote)
        mag = list(magazine)
        for i in ran:
            if i in mag:
                mag.remove(i)
            else: 
                return False
        return True
```