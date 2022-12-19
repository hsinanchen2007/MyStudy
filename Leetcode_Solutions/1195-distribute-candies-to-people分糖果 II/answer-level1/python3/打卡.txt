class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people
        
        def helper(candies, ind, needCan):
            if candies < 0:
                return
            ans[ind] += min(candies, needCan)

            if candies - needCan > 0:
                ind += 1
                helper(candies - needCan, ind % num_people, needCan + 1)
        
        helper(candies, 0, 1)

        return ans
            