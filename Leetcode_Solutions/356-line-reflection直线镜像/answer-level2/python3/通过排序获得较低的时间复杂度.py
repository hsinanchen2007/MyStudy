对y值进行排序，然后按照不同y值看是否满足镜像要求。
时间复杂度由排序算法决定o(nlgn),空间复杂度由排序算法和相同y值的最大点数决定，最好情况o(1),最差情况o(n)
```
class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        if len(points) == 0:
            return True
        points = sorted(points,key = lambda x:x[1])
        pre = points[0][1]
        l = 0
        n = len(points)
        flag = 0
        for i in range(n):
            if i == n-1 or points[i+1][1] != pre:
                nums = []
                for j in range(l,i+1):
                    nums.append(points[j][0])
                if flag == 0:
                    m = max(nums)+min(nums)
                    flag = 1
                for num in nums:
                    if m - num not in nums:
                        return False
                if i < n-1:
                    pre = points[i+1][1]
                l = i + 1
        return True
```
