### 解题思路
- 找到h篇文章，引用至少是h,h即为H指数
- h的搜索范围是len(citations)递减至0

### 代码

```python3
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        for h in range(len(citations),-1,-1):
            if [each>=h for each in citations].count(True)>=h:
                return h
        return 0

```