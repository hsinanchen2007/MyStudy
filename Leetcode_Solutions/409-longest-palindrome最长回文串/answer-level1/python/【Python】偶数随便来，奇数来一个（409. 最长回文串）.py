## 思路


这道题是一个小小的脑筋急转弯，类似的LeetCode题目有很多，大家做多了就很快能想到，不会掉坑里。

具体算法：

- 统计所有的字符出现的次数。
- 如果一个字符出现了偶数次，那么随便来，全盘接受。
- 如果一个字符出现了奇数次，我们最多选一个，放到回文串的中间位置。 类似： xxxxxxaxxxxxx

## 代码

```python
from collections import Counter

class Solution:
    def longestPalindrome(self, s: str) -> int:
        counter, odd = Counter(s), 0
        for v in counter.values():
            if v % 2 == 1:
                odd += 1
        return len(s) - max(odd - 1, 0)
```

如果你喜欢简洁的代码：

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        return len(s) - max(sum(v % 2 == 1 for v in collections.Counter(s).values()) - 1, 0)
```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)