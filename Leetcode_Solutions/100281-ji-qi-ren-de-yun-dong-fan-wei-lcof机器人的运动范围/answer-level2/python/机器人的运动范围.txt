经过分析可以知道满足位数之和小于k的解其实可以分为两种情况：
  （1）以(0,0)为起始点的三角形
  （2） 以(i,j)为起始点的三角形
而且可以看到两种三角形不是连通的，也就是说我们只需要记录以(0,0)为起始点的三角形的格子数即可
所以：机器人可仅通过向右和向下移动，访问所有可达解
可以使用广度优先搜索算法计算三角形的格子数量。
代码如下：
```
class Solution(object):
    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        # 如果k=0，则返回1
        if not k:
            return 1
        # 计算一个数字各数位的和
        def ComputeNums(num):
            nums = 0
            while num:
                nums += num % 10
                num //= 10
            return nums
        # 广度优先搜索
        def DFS(i, j):
            if i < 0 or j < 0 or i >= m or j >= n \
                    or (i, j) in visite or ComputeNums(i) + ComputeNums(j) > k:
                return 0
            visite.add((i, j))
            nums = 1
            nums += DFS(i+1, j)
            nums += DFS(i, j+1)
            return nums
        # 定义一个集合，判断当前位置是否被访问过
        visite = set()
        return DFS(0, 0)
```

