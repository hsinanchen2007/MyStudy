### 解题思路
我们统计每个字符出现的个数，如果发现该字符仅出现一次，立即返回。如果我们遍历到结尾没有找到目标字符，返回 `" "`。

### 代码

```python []
class Solution:
    def firstUniqChar(self, s: str) -> str:
        dic = collections.Counter(s)
        for i in s:
            if dic[i] == 1:
                return i
        return ' '
```
### 复杂度分析
- 时间复杂度：$O(N)$，一趟遍历。
- 空间复杂度：$O(N))$，使用了哈希表。