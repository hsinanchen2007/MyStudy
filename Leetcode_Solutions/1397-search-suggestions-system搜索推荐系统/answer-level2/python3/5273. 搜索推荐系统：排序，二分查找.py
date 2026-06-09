时间复杂度$O((M+N)logM)$，其中$M$为`products`的长度，$N$为`searchWord`的长度，最快72ms，仅供参考。
```python []
class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        for i in range(1, len(searchWord) + 1):
            ans, j = [], bisect.bisect_left(products, searchWord[: i])
            while j < len(products) and products[j].startswith(searchWord[: i]) and len(ans) < 3:
                ans.append(products[j])
                j += 1
            yield ans 
```