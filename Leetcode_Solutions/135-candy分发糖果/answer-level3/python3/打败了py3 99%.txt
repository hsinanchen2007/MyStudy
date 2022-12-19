```
class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        res = len(ratings)
        if res <2:
            return res
        candy = [1 for _ in ratings]
        l=0
        r=len(ratings)
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1] and candy[i]<=candy[i-1]:
                candy[i]=candy[i-1]+1
        for i in range(len(ratings)-2, -1, -1):
            # print(ratings[i])
            if ratings[i] > ratings[i+1] and candy[i]<=candy[i+1]:
                candy[i]=candy[i+1]+1
        # print(candy)
        
        return sum(candy)
        





```
