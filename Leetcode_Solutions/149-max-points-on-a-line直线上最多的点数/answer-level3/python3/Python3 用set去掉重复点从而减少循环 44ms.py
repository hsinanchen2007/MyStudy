维护一个重复点的次数的hash_map
从而避免对同一个点多次循环
```
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        k_b = {}
        repeated = {}
        points = [tuple(point) for point in points]
        for point in points:
            if point in repeated:
                repeated[point]+=1
            else:
                repeated[point] = 1
        points = list(set(points))
        if len(points) <3:
            total = 0
            for key in repeated.keys():
                total+=repeated[key]
            return total

        max_nums = 2
        for i in range(len(points)):
            for j in range(i+1,len(points)):
                x1, y1 = points[i]
                x2, y2 = points[j]

                if x1 == x2:
                    k = x1
                    b = math.inf
                else:
                    k = (y1-y2)/(x1-x2)
                    b = y1 - x1*k
                
                if (k,b) not in k_b:
                    k_b[(k,b)] = [points[i],repeated[points[i]]+repeated[points[j]]] 
                else:
                    if points[i]==k_b[(k,b)][0]:
                        k_b[(k,b)][1] += repeated[points[j]]
                        max_nums = max(k_b[(k,b)][1], max_nums)
        return max_nums
```


