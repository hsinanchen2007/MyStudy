class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        left = 1
        right = 1000
        list = []
        while(left <= 1000 and right >=1):
            temp = customfunction.f(left, right)
            if(temp == z):
                res = []
                res.append(left)
                res.append(right)
                list.append(res)
                left += 1
            elif(temp > z):
                right -= 1
            else:
                left += 1
        return list