####  方法1：遍历

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|    O(n)    |    O(l)    |

**基本思路：**

> 如代码注释。

**代码：**

```python []
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        # 至多有h篇论文分别被引用了至少h次
        # 数组长度为n，某个元素索引为i
        # 有n-i篇论文至少被引用了citations[i]次
        # 若citations[i]满足要求，则citations[i] >= n-i

        n = len(citations)
        for i in range(n):
            if citations[i] >= n - i:
                return n - i
        return 0
```

####  方法2：遍历

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|  O(logn)   |    O(l)    |

**基本思路：**

> 思路跟上面一样，通过二分法查找相应元素。

**代码：**

```python []
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        # 至多有h篇论文分别被引用了至少h次
        # 数组长度为n，某个元素索引为i
        # 有n-i篇论文至少被引用了citations[i]次
        # 若citations[i]满足要求，则citations[i] >= n-i
        n = len(citations)
        l, r = 0, n - 1
        tmp = 0
        while l <= r:
            m = (l + r) // 2
            # 判断条件
            if citations[m] >= n - m:
                tmp = n - m
                r = m - 1
            else:
                l = m + 1
        return tmp
```