### 解题思路
题目中已经给了足够多的暗示，本题可以理解为求一棵树的最大深度。我们只需从根节点开始，采用深度优先搜索，求出这棵树的最大深度即可。

可以看到题目中给出的是数组而非树的结构，因此首先需要存储树的结构（即父子关系）。一般来讲有两种存储方法：
- 邻接矩阵
- 二维数组

我们使用二维数组 $son$ 保存父节点为 $i$ 的孩子结点 $son[i]$，然后采用深度优先搜索。

### 代码

```cpp []
class Solution {
public:
    // 存结点
    vector<vector<int>> son;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        son = vector<vector<int>> (n);
        for (int i = 0; i < n; i ++){
            if (i != headID){
                son[manager[i]].push_back(i);
            }
        }
        return dfs(headID, informTime);
    }

    int dfs(int u, vector<int>& informTime){
        int res = 0;
        for (auto s : son[u]) res = max(res, dfs(s, informTime));
        return res + informTime[u];
    }
};
```

```python []
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        self.son = collections.defaultdict(list)
        for i in range(n):
            if i != headID:
                self.son[manager[i]].append(i)
        
        return self.dfs(headID, informTime)
    
    def dfs(self, u, informTime):
        res = 0
        for s in self.son[u]:
            res = max(res, informTime[u] + self.dfs(s, informTime))
        return res
```
### 复杂度分析
- 时间复杂度：$O(n)$，遍历了每一个结点。
- 空间复杂度：$O(n)$，使用了数组存储每一个结点。