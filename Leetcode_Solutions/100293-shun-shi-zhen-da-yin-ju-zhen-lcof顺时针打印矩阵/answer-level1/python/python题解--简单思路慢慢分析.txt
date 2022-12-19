### 解题思路
![image.png](https://pic.leetcode-cn.com/bdb0827332a7e02859a72c75a7a1f95edfb55c3f8f3d73c867c01a8e088c970d-image.png)

- 我参考剑指offer的题解,下面分析下思路,如果大家有好的想法请评论我,谢谢!!!
- 我么可以想象成是对数组进行一圈一圈的遍历
- 举例,对于一个`5*5`的矩阵而言,最后一个圈只有一个数字,对应的坐标为`(2,2)`.我们发现`5>2*2`.
- 对于一个`6*6`的矩阵而言,最后一圈有四个数字,其左上角的坐标仍然是`(2,2)`.可以发现`6>2*2`.
- 于是可以得出让循环技术的条件,也就是我们遍历到最后一个圈的条件是`colums > start*2 and raw > start*2`,初始时`start=0`,`colums`,`raw`分别为数组的列和行.对于这个终止条件我自己是想象成从最内圈每多出一圈相当于在原来的基础上扩大了二倍.
- 好了!现在我们有了终止条件了,下面开始写详细的步骤:
- 我们可以分为四部,这四部是连续的:
1. 从左到右的打印
- 这个直接打印就可以了,除非数组为空
2. 从上到下打印
- 这个的前提是最少有两行,也就是`end_raw > start`
3. 从右往左打印
- 这个的条件是最少有两行两列,也就是`end_raw > start and end_col > start`
4. 从上到下打印
-  这个的条件是最少有三行两列,也就是`end_col > start and end_raw -1 > start`

- 时间复杂度为`O(n)`,空间复杂度`O(1)`
- 这个题需要理清楚关系,没有涉及到任何数据结构或者高级算法
### 代码

```python
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        raw = len(matrix)
        columns = len(matrix[0])
        start = 0
        result = []
        while (columns > 2 * start and raw > 2 * start):
            end_col = columns - start - 1
            end_raw = raw - start - 1

            #从右往左打印一行
            for i in range(start, end_col + 1):
                result.append(matrix[start][i])
            
            #从上到下打印
            if start < end_raw:
                for i in range(start + 1, end_raw + 1):
                    result.append(matrix[i][end_col])
            
            #从左往右打印
            if start < end_raw and start < end_col:
                for i in range(end_col-1, start-1, -1):
                    result.append(matrix[end_raw][i])

            #从上到下打印
            if start < end_col and start < end_raw - 1:
                for i in range(end_raw-1, start, -1):
                    result.append(matrix[i][start])
            
            start += 1

        return result


```