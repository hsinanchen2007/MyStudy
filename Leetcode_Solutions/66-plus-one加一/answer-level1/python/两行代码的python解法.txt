思路： 原始列表 - > 字符串 -> 整数 -> 整数加1求和 -> 和转字符串 -> 字符串转列表
```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = int(''.join(map(str, digits))) + 1
        return list(map(int, str(num)))
```
