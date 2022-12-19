### 解题思路
建立管理者-员工表, dfs求解

### 代码

```java []
class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        if(n <= 0)
            return 0;
        // dfs算法
        G = new ArrayList [n];
        // 初始化管理表
        for(int i=0; i<n; ++i)
            G[i] = new ArrayList<>();
        
        // 领导节点添加员工
        for(int i=0; i<n; ++i){
            if(i != headID)
                G[manager[i]].add(i);
        }
        
        this.res = 0;
        dfs(headID, informTime[headID], informTime);
        return res;
    }

    private void dfs(int index, int info, int[] informTime){
        for(int id: G[index]){
            this.res = Math.max(this.res, info);
            dfs(id, info+informTime[id], informTime);
        }
    }
```
```python []
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        if n <= 0:
            return 0

        self.G = [[] for _ in range(n)]
        for i in range(n):
            if i != headID:
                self.G[manager[i]].append(i)

        self.res = 0
        self.dfs(headID, informTime[headID], tuple(informTime))
        return self.res

    def dfs(self, index, info, informTime: tuple):
        for id in self.G[index]:
            self.res = max(self.res, info)
            self.dfs(id, info+informTime[id], informTime)
```
```c++ []
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // dfs
        for(int i=0; i<n; ++i){
            if(i != headID){
                G[manager[i]].push_back(i);
            }
        }
        res = 0;
        dfs(headID, informTime[headID], informTime);
        return res;
    }

private:
    void dfs(int id, int inform, const vector<int>& informTime){
        if(G[id].empty())
            res = max(res, inform);
        for(int i: G[id]){
            dfs(i, inform+informTime[i], informTime);
        }
    }

private:
    vector<int> G[100005];
    int res;
};
```