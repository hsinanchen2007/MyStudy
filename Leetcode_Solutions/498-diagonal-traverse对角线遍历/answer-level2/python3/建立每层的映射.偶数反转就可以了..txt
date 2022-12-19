每层遍历的时候, i+j 相等.依据这个可以建立一个映射,记录每层遍历的所有值.
那么我们只需要按顺序从上到下遍历就可以获得每层倾斜的遍历.
例如:
[1,2,3]
[4,5,6]
[7,8,9]
dic =  {
0: [1],
1: [2, 4],
2: [3, 5, 7],
3: [6, 8],
4: [9]})
偶数层再反转一下就行了.
```
from collections import defaultdict
class Solution:
    def findDiagonalOrder(self, matrix: list) -> list:
        if not matrix:
            return []
        r,l = len(matrix),len(matrix[0])
        dic = defaultdict(list)
        for i in range(r):
            for j in range(l):
                dic[i+j].append(matrix[i][j])
        res = []
        for i in range(len(dic)):
            if i & 1:
                res.extend(dic[i])
            else:
                res.extend(dic[i][::-1])
        print(dic)
        return res
```
