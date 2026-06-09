```python
class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        # Time complexity: O(M * N) <= O(10 ** 6)
        ans = []
        def judge(query, pattern):
            j = 0
            for i in range(len(query)):
                if j < len(pattern):
                    if pattern[j] == query[i]: j += 1
                    elif query[i].isupper(): return False
                elif query[i].isupper():  return False
            return j == len(pattern)

        for query in queries:
            ans.append(judge(query, pattern))
        return ans
```