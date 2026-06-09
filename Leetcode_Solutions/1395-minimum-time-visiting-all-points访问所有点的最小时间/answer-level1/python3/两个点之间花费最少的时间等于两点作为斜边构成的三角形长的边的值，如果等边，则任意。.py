class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        i = 0
        count = 0
        while i < len(points)-1:
            length = abs(points[i][0]-points[i+1][0])
            width = abs(points[i][1]-points[i+1][1])
            if length >= width:
                count += length
            else:
                count+=width
            i+=1
        return count