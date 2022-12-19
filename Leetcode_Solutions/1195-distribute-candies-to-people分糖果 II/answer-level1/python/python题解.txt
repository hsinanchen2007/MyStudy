```
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        result = [0 for _ in range(num_people)]
        t = 0
        while candies > 0:
            temp = t*num_people
            for i in range(num_people):
                n = i+1+temp
                if candies >= n:
                    result[i] += n
                    candies -= n
                else:
                    result[i] += candies
                    candies -= n
                    break
            t += 1 
        return result
```
