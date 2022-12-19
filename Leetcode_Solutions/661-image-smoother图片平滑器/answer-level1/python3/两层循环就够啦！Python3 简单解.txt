## 思路
+ 题目不难，但是很多写法有多层循环，写法不够 Pythonic
+ 其实两层循环就够了
+ 第一层循环，遍历所有的点
+ 第二层循环，遍历这些点的邻居
+ 利用 Python 循环可以用两个变量的特性即可

## 代码
```python
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        ans = [[0] * len(M[0]) for _ in M]
        for row,col in [(i,j) for i in range(len(M)) for j in range(len(M[0]))]:
            count = 0
            for dx,dy in [(i,j) for i in range(row - 1,row + 2) for j in range(col - 1,col + 2)]:
                if 0 <= dx < len(M) and 0<= dy < len(M[0]): 
                    ans[row][col] += M[dx][dy]
                    count += 1
            ans[row][col] //= count
        return ans
```