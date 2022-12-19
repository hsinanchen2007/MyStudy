class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        point1 = points[0]
        point2 = points[1]
        point3 = points[2]
        print(point1[0])
        print(point1[0]+1)

        if point1 == point2 or point2 == point3 or point1 == point3:
            return False
        if point1[0]+1 == point2[0] and point1[1]+1 == point2[1] and ++point2[0]+1 == point3[0] and point2[1]+1 == point3[1]:
            print(1)
            return False
        if point1[0] == point2[0] == point3[0]:
            print(3)
            return False
        if point1[1] == point2[1] == point3[1]:
            print(4)
            return False
        else:
            return True