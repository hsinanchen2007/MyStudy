```
class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        dic = {}
        sister = 0
        sister_num = 0
        for i in candies:
            if sister_num == len(candies)//2:
                break
            if i not in dic:
                dic[i] = 1
                sister += 1
                sister_num += 1
                
            elif dic[i]%2 == 0:
                dic[i] += 1
                sister_num += 1
        return sister
```
