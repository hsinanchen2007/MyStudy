class Solution:
```
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0 for _ in range(num_people)]
        if not candies:
            return res
        round = 0
        total_count = num_people * (num_people + 1) / 2
        while candies > total_count:
            candies = int(candies - total_count)
            round += 1
            total_count = round * num_people * num_people + num_people * (num_people + 1) / 2
        for i in range(num_people):
            res[i] += int(num_people * round * (round - 1) / 2 + (i + 1) * round)
            temp = int(num_people * round + i + 1)
            res[i] += temp if candies >= temp else candies
            candies = int(candies - temp)
            if candies <= 0:
                candies = 0
        return res
```
    