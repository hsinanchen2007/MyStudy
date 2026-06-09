### 解题思路
![image.png](https://pic.leetcode-cn.com/e4aab734c2e1ed9d242bc54c52febc2e0ec899431fe5031c2263f5d8b78e4966-image.png)
- 本题采用回溯法解决,其实思路是不困难的,把各个细节掌握好
- 我们考虑这个机器人走过的路径,我们很容易想到用递归的方法,但是那些路径上会出现重复走的情况,所以我们需要设定一个访问数组`visited`来保存当前的这个点是否访问过,若果访问过就不在访问了,如果没有访问过就将这个点的设置成访问过,在继续遍历当前节点的前后左右节点
- 记得把题目的先定条件加好就可以了


### 代码

```python
class Solution(object):
    def movingCount(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        visited = [[0] * n for _ in range(m)]
        return self.movingCountCore(m, n, k, 0, 0, visited)
    
    def movingCountCore(self, m, n, k, row, col, visited):
        count = 0
        if self.check(m, n, k, row, col, visited):
            visited[row][col] = 1 
            count = 1 + self.movingCountCore(m, n, k, row+1, col, visited)+ \
                        self.movingCountCore(m, n, k, row-1, col, visited) + \
                        self.movingCountCore(m, n, k, row, col+1, visited) + \
                        self.movingCountCore(m, n, k, row, col-1, visited)
        return count
    
    def check(self, m, n, k, row, col, visited):
        if row >= 0 and row < m and col >= 0 and col < n and not visited[row][col] and (self.sum_(row) + self.sum_(col)) <= k:
            return True
        return False
    def sum_(self, num):
        temp = 0
        while num > 0:
            temp += num % 10
            num /= 10
        return temp

        

    
```