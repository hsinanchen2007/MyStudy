```
class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        
        my_dict = {0: 0}
        
        for l in wall:
            s = 0
            if len(l) == 1:
                continue

            for v in l[:-1]:
                s += v
                my_dict[s] = my_dict.get(s, 0) + 1
        
        return len(wall) - max(my_dict.values())
```
执行用时 :164 ms, 在所有 python 提交中击败了100.00%的用户

