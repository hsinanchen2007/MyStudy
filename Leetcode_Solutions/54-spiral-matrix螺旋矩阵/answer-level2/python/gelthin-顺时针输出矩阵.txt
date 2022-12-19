### 解题思路
参考官方题解 [螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/solution/luo-xuan-ju-zhen-by-leetcode/)

### 模拟：采用方向旋转法
用一个矩阵标记已经走过的路线，
每次朝当前方向前进一步，若已访问过或者越界，则转向下一个方向走一步，若仍访问过或者越界，则说明全部访问完了，停止。

### 官方题解法2：
从最外圈开始，使用顺时针访问整个一圈的节点，然后再访问往里一圈的节点。直到最终的节点。


这一题也看到有人用 90°顺时针旋转矩阵法+额外操作，这个是套用了 [面试题 01.07. 旋转矩阵](https://leetcode-cn.com/problems/rotate-matrix-lcci/solution/gelthin-duo-chong-jie-fa-by-gelthin/) [48. 旋转图像](https://leetcode-cn.com/problems/rotate-image/) 的解答。
[拿一行，逆时针转一下](https://leetcode-cn.com/problems/spiral-matrix/solution/luo-xuan-ju-zhen-by-leetcode/130844)






### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ## 模拟转弯，标记是否访问过
        if matrix == []:
            return []
        else:
            m, n = len(matrix), len(matrix[0])

        seen = [[None]*n for _ in range(m)] #快速构造一个标记矩阵
        dx = [0,1,0,-1]  ## 所有的四种方式，按顺时针
        dy = [1,0,-1,0]  

        result = []
        i, j = 0, 0
        k = 0
        while 0<=i<m and 0<=j<n and not seen[i][j]:  ## 下面也进行判断
            seen[i][j] = True
            result.append(matrix[i][j])
            n_i, n_j = i+dx[k], j+dy[k]
            # if not 0<=n_i<=m or not 0<=n_j<=n or seen[n_i][n_j]:
            if 0<=n_i<m and 0<=n_j<n and not seen[n_i][n_j]:
                i, j = n_i, n_j
            else:  # 当前方向再走一步，越界或者访问过
                k = (k+1)%4     # 看转方向后走一步是否仍然越界，或者是否仍访问过
                i, j = i+dx[k], j+dy[k]  
        return result



```