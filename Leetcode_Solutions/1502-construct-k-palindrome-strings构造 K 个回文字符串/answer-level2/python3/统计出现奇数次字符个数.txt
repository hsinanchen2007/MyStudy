### 解题思路

统计每个字符出现的次数，出现偶数次是不会影响结果，只有出现奇数次的才会影响

然后判断奇数次的字符和k的关系

当然还有一些平凡情况：
- 字符串个数小于k False
- 字符串个数等于k True

### 代码

```python3
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        tmp = {}
        if len(s) < k:
            return False
        if len(s) == k:
            return True

        for char in s:
            if char in tmp:
                tmp[char] += 1
            else:
                tmp[char] = 1

        
        n = 0
        for x in tmp:
            if tmp[x] % 2:
                n += 1
        return n <= k
```