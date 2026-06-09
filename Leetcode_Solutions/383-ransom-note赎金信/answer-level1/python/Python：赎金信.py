### 解题思路
这道题主要考察重复元素集合的关系
所以set不能用，那就使用collection.Counter，它也有一部分集合运算功能
判断标准：在ransomNote中不存在比magazine多的元素

### 代码

```python3
import collections
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        return False if collections.Counter(ransomNote)-collections.Counter(magazine) else True
```