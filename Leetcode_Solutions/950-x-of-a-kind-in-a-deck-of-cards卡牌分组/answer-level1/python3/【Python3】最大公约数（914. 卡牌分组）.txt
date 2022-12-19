## 思路

- 首先统计下每个数字的出现次数（实际上我们只关心出现的次数，不关心数字本身是几）
- 然后求解这些分组的最大公约数
- 如果大于1，说明我们可以找到这样的分组

## 代码

```python
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        def gcd(a, b):
            if b == 0: return a
            return gcd(b, a % b)
        return reduce(gcd, collections.Counter(deck).values()) > 1
```


**复杂度分析**

- 时间复杂度：$O(N)$
- 空间复杂度：空间复杂度取决于递归的深度，因此空间复杂度为 $O(log(max(a, b)))$。如果你将上述过程改成迭代，那么可以降低到$O(1)$，也不难，大家可以自己试试。

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae452e3ab90392e328c2670cddc-file_1581478989502)