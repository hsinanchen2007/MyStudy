### 解题思路
此处撰写解题思路

屏幕快照 2020-04-06 下午10.39.50
![image.png](https://pic.leetcode-cn.com/0eb7a4c77d290cfce4bb5e226c806b1cf3b30a9b1de07dbb057ae0658e1835b9-image.png)
### 代码

```python
class Solution(object):
    def numberOfPatterns(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        res = 0
        # 当前点key，不能直接到的下一点的字典
        graph = {
            1:{3:2, 7:4, 9:5},
            2:{8:5},
            3:{1:2, 7:5, 9:6},
            4:{6:5},
            5:{},
            6:{4:5},
            7:{1:4, 3:5, 9:8},
            8:{2:5},
            9:{1:5, 3:6, 7:8}
        }

        # status 存储经过的点，位图
        def dfs(status, current, count):
            if count == n:
                return 1
            current_res = 0 if count < m else 1
            for i in range(1, 10):
               # 判断下一步i点是否走过
               if status & (1<<i) == 0:
                   # 如果能够直达，即下一步i点不在graph[current]中，更新状态，递归
                   # 如果不能直达，即i点在graph[current]，
                   #     判断若到下一个点i，所要跨过的点是不是已经经过了
                   if (i not in graph[current]) or (1<<graph[current][i] & status):
                      current_res +=  dfs(status|1<<i, i, count+1)
            return current_res

        res += 4*dfs(1<<1, 1, 1)
        res += 4*dfs(1<<2, 2, 1)
        res += dfs(1<<5, 5, 1)

        return res
```