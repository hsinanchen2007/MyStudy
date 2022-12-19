### 解题思路
![1.png](https://pic.leetcode-cn.com/d7e88bf083220870513e7e4ce6709908940afeb0e4d9a13248587e80ecac280e-1.png)

首先想办法找到计算 矩阵中任意一块矩形内部和的方法。
再想办法去找边长。如果能找到合适的控制边长的条件，能节省很多次寻找。

### 代码

```python3
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        # 这是计算mat[0][0]到mat[i][j]的
        # def get_sum(matrax):
        #     if matrax == [] or matrax == [[]]:
        #         return
        #     m = len(matrax)
        #     n = len(matrax[0])
        #     sum_all = [[0 for _ in range(n+1)] for i in range(m+1)]
        #     shang = 0
        #     for i in range(m):
        #         print(shang)
        #         for j in range(n):
        #             sum_all[i+1][j+1] = sum_all[i+1][j] + matrax[i][j] + shang
        #             shang = 0
        #         shang = sum_all[i+1][n]
        #     return sum_all
        
        # 这是计算mat[i][j]左上角矩形的
        def get_juxing_sum(matrix):
            if matrix == [] or matrix == [[]]: return
            row, col = len(matrix), len(matrix[0])
            sum_arr = [[0] * (col + 1) for _ in range(row + 1)]
            self.update_dic = collections.defaultdict(int)

            for i in range(row):
                left = 0
                for j in range(col):
                    sum_arr[i + 1][j + 1] = sum_arr[i][j + 1] + left + matrix[i][j]
                    left += matrix[i][j]
            # print(sum_arr)
            return sum_arr

        # juxing_sum是多了一行一列的
        juxing_sum = get_juxing_sum(mat)
        m = len(mat)
        n = len(mat[0])
        z = 0
        for k in range(1,min(m+1,n+1)):
            # 当边长比上次记录的大一个都没有找到合适的
            # 那么就不用再继续下去了，省了很多次判断
            if k-z >=2:
                break
            else:
                for i in range(1,m+1):
                    # 已经找到了合适的k了，也就没必要再去找了
                    if z<k:
                        for j in range(1,n+1):
                            # 第一个判断同上道理，后面判断是边长不能超出范围
                            if z>=k or i+k>m+1 or j+k>n+1:
                                continue
                            s = 0
                            s1 = juxing_sum[i+k-1][j+k-1]
                            s2 = juxing_sum[i-1][j-1]
                            s3 = juxing_sum[i-1][j+k-1]
                            s4 = juxing_sum[i+k-1][j-1]
                            s = s1+s2-s3-s4
                            if s<= threshold:
                                z = max(z,k)
                    else:
                        continue
        # print(z)
        return z
```