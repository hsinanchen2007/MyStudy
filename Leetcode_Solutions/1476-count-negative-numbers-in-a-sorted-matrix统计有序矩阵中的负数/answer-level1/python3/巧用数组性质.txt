一 方法1（O(N**2)时间复杂度）
（一）算法思想
数组中从左到右非递增，从上到下非递增，则搜索到某一行第一个负数时，该数后边所有数皆为负，该数下边所有数皆为负，也就是说以该数为顶点，到数组右下角的矩形区域均为负。
为此，可以从上到下逐行搜索每行的第一个负数，搜索到该负数时，将以其为顶点到数组右下角的矩形区域的元素个数加进结果，并将这部分元素抹去，防止重复计算。这样处理完所有行时，就可得到结果。
（二）算法实现
```
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        i = 0
        res = 0
        while i < m:
            j = 0
            while j < n:
                if grid[i][j] < 0:
                    res += (m-i) * (n-j)
                    n = j
                    break
                else:
                    j += 1
            i += 1
        return res
```
（三）复杂度分析
时间复杂度:O(N**2)
空间复杂度:O(1)
二 方法2（O(N)时间复杂度）
（一）算法思想
参考一，不过这次为进一步利用矩阵的性质自右向左遍历每行，列指针j无需归0，可显著减少时间复杂度
（二）算法实现
```
        # method2
        m = len(grid)
        end = len(grid[0]) - 1
        res = 0
        i = 0
        j = end
        while i < m:
            while j >= 0:
                if grid[i][j] >= 0:
                    res += (m - i) * (end - j)
                    end = j
                    break
                else:
                    j -= 1
            if j == -1:
                res += (m - i) * (end - j)
                break
            i += 1
        return res
```
（三）复杂度分析
虽然两层循环，但指针j并归位，时间复杂度其实为O(N)。
