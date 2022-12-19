### 解题思路
维护窗口大小为len(s1)的两个指针i和j，在字符串s2上滑动，判断窗口内的hash表是否和s1的hash表一致。

### 代码

```python3
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        import collections
        count_dict = collections.Counter(s1)
        m = len(s1)
        i = 0
        j = m - 1
        while j < len(s2):
            if collections.Counter(s2[i:j+1]) == count_dict:
                return True
            i += 1
            j += 1
        return False
```
欢迎关注的我的[github](https://github.com/tcandzq/LeetCode)，查看更多精彩题解。