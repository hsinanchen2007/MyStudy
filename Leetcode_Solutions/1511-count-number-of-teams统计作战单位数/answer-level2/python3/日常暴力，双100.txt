依次循环选择i，j，k，满足条件时计数
```
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        s = 0
        for i in range(len(rating)):
            for j in range(len(rating)):
                for k in range(len(rating)):
                    if i<j and i<k and j<k:
                        if rating[i]<rating[j] and rating[i]<rating[k] and rating[j]<rating[k]:
                            s+=1
                        if rating[i]>rating[j] and rating[i]>rating[k] and rating[j]>rating[k]:
                            s+=1
        return s
```
