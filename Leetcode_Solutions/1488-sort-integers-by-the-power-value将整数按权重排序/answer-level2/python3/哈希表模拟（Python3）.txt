### 解题思路

首先使用哈希表 $dic$ 保存每个 x 对应的权重，即 `{x:weights}`，然后使用 lambda 表达式进行排序，最后返回第 `k` 个数即可。

类似的排序方法会经常用到，留意一下就好。

### 代码
```python []
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        dic = {}
        for x in range(lo, hi + 1):
            cnt = 0
            m = x
            while x != 1:
                if x % 2 == 0:
                    x = x // 2
                    cnt += 1
                else:
                    x = 3 * x + 1
                    cnt += 1
            dic[m] = cnt
        dic = sorted(dic.items(),key = lambda x: (x[1],x[0])) # 先按 value 排，再按 key 排
        return dic[k - 1][0]
```
### 复杂度分析
- 时间复杂度：$O(nlogn)$。
- 空间复杂度：$O(n)$。