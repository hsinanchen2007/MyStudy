### 解题思路
此处撰写解题思路
观察题目可以发现只有每个位置都往下或往右走才是最短路径
可以把[0,0]看作是开始节点
![捕获.PNG](https://pic.leetcode-cn.com/eccc55a4f8532ee69a3a278a96ac639d0448c1cdfa1b6ce7519f2fc62bb403da-%E6%8D%95%E8%8E%B7.PNG)
按照拓扑排序更新每个节点到开始节点的最短路径

### 代码

```python
from collections import deque
class Solution(object):
    def minPathSum(self, l):
        m,n=len(l),len(l[0])
        for i in range(m):
            for j in range(n):
                if i==0 and j==0:
                    continue
                elif i==0 and j>0:
                    l[i][j]=l[i][j-1]+l[i][j]
                elif j==0 and i>0:
                    l[i][j]=l[i-1][j]+l[i][j]
                else:
                    l[i][j]=min(l[i-1][j],l[i][j-1])+l[i][j]
        return l[-1][-1]
```