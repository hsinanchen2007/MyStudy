我们全部遍历一次，对于每一个格子都进行一次判断: `行坐标和列坐标的数位之和是否小于等于k`，如果是则计数器+1，最后我们返回计数器的值。 


```python
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        cnt = 0
        for i in range(m):
            for j in range(n):
                if sum(map(lambda a: int(a), str(i) + str(j))) <= k:
                    cnt += 1
        return cnt      
```

上面的解法是有bug的。比如当前格子虽然满足条件，但是其不可达（即四周的格子都不满足）：

![](https://pic.leetcode-cn.com/e85315a2b14826bcd32da19dd92fc92c894a0f207dc12c938b0eead3499fec12.jpg)



因此我们考虑从（0，0） 开始进行dfs，并使用visited 记录访问情况即可。

```python
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def dfs(i, j):
            if (i, j) in self.visited or i < 0 or i >= m or j < 0 or j >= n:
                return
            self.visited.add((i, j))
            if sum(map(lambda a: int(a), str(i) + str(j))) <= k:
                self.cnt += 1
                dfs(i + 1, j)
                dfs(i - 1, j)
                dfs(i, j + 1)
                dfs(i, j - 1)
        self.visited = set()
        self.cnt = 0
        dfs(0, 0)
        return self.cnt
    
            
```

> 值得注意的是，我们visited和cnt不能放到类内初始化，而是放到movingCount中初始化


欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)