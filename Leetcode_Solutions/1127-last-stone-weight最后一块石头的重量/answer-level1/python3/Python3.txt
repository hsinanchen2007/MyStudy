```
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:    
        req_sorted = True    
        while len(stones)> 1:
            if req_sorted:
                stones = sorted(stones, key=lambda x: 0-x)
            x1, x2 = stones[0], stones[1]
            stones = stones[2:]
            if x1 == x2:
                continue
            else:
                new_stone = abs(x1-x2)
                req_sorted = (len(stones) > 0) and (new_stone > stones[-1])
                stones.append(new_stone)

        return 0 if len(stones) == 0 else stones[0]
```
