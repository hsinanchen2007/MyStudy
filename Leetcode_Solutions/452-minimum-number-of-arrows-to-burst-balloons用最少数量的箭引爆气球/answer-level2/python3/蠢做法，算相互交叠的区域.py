# 和大牛的思路刚好是反的，羞耻地记录一下吧😄

# ```
class Solution:
    def findMinArrowShots(self, points) -> int:
        if not points: return 0
        
        points.sort()
        count = 0

        cur_start = points[0][0]
        cur_end = points[0][1]

        for i in range(len(points)):
            start, end = points[i][0], points[i][1]
            
            if cur_start < start <= cur_end:
                cur_start = start     
                if end < cur_end:
                    cur_end = end

            elif cur_end < start:
                count += 1
                cur_start = start
                cur_end = end

            
            if i == len(points) - 1:
                count += 1
        
        return count
# ```
