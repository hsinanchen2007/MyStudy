### 解题思路
Counter方法：计数，并把每个元素出现次数和元素值作为键--值对保存为Counter对象
如果ransomNote中的字符及出现个数大于magazine中的字符出现个数，就满足题意

### 代码

```python3
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        return not collections.Counter(ransomNote)-collections.Counter(magazine)
```