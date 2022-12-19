class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        n = len(coordinates)
        x1 = coordinates[0][0]  # 根据前两个点，找到斜率k和常量b
        x2 = coordinates[1][0]
        y1 = coordinates[0][1]
        y2 = coordinates[1][1]
        if(x1!= x2):
            global k
            global b
            k = (y1 - y2)/(x1 - x2)
            b = (x1*y2-x2*y1)/(x1-x2)
        # 判断第三个点是否在前两个点构成的直线上。
        for i in range(2, n): 
            x_test = coordinates[i][0]
            y_test = k*x_test + b
            if (y_test != coordinates[i][1]):
                return False
            else:
                continue
        return True
            