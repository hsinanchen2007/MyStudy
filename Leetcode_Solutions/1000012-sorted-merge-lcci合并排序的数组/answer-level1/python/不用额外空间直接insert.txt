```
        point1 = 0
        point2 = 0
        while point2 < n and point2+m>point1:
            if B[point2] <= A[point1]:
                A.insert(point1,B[point2])
                point2 += 1
                point1 += 1
            elif B[point2] > A[point1]:
                point1 += 1
        if point2 != n:
            while point2 < n:
                A.insert(point1,B[point2])
                point2 += 1
                point1 += 1
        for i in range(n):
            A.pop()
```
