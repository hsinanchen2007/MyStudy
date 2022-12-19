```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        # each child must have at least one candy.
        # children get more candies with a higher rating.

        # [1, 0, 2]
        # [2, 1, 2]

        # forward: [1, 1, 2]
        # backward:[2, 1, 2]
        if len(ratings) == 1: return 1
        elif len(ratings) == 0: return 0
        candies = [1] * len(ratings)
        # forward traverse:
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
        # backward traverse:
        for i in range(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)
        return sum(candies)
```