```python
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        # thickness:  books[i][0]
        # height:     books[i][1]
        # order: books order

        # Time complexity : O(N ** 2)
        # Space complexity : O(N)

        b_length = len(books)
        dp = [0] + [float('inf')] * b_length
        for i in range(1, b_length + 1):
            max_height, sum_width = 0, 0
            for j in range(i, 0, -1):
                sum_width += books[j - 1][0]
                if sum_width > shelf_width: break
                max_height = max(max_height, books[j - 1][1])
                dp[i] = min(dp[i], dp[j - 1] + max_height)
        return dp[-1]
```