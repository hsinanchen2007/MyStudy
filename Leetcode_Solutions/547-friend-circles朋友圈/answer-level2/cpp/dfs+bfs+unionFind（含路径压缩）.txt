### 解题思路
并查集参考了其他同学的做法，用了路径压缩和按秩合并

### 代码

```cpp
#if 0
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int result = 0;
        vector<int> visited(M.size(), 0);
        
        for (int i = 0; i < M.size(); ++i) {
            if (visited[i] == 0) {
                result += 1;
                dfs(M, visited, i);
            }
        }
        
        return result;
    }
private:
    void dfs(const vector<vector<int>>& matrix, vector<int>& visited, int cur) {
        visited[cur] = 1;

        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[cur][i] == 1 && visited[i] == 0 && cur != i) {
                dfs(matrix, visited, i);
            }
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int result = 0;
        vector<int> visited(M.size(), 0);
        
        for (int i = 0; i < M.size(); ++i) {
            if (visited[i] == 0) {
                result += 1;
                bfs(M, visited, i);
            }
        }
        
        return result;
    }
private:
    void bfs(const vector<vector<int>>& matrix, vector<int>& visited, int cur) {
        queue<int> que;
        que.push(cur);
        
        while (!que.empty()) {
            int current = que.front();
            que.pop();
            visited[current] = 1;
            
            for (int i = 0; i < matrix.size(); ++i) {
                if (matrix[current][i] == 1 && visited[i] == 0 && current != i) {
                    que.push(i);
                }
            }
        }
    }
};
#endif

class mergeFind {
public:
    mergeFind(int num) {
        count = num;
        for (int i = 0; i < num; ++i) {
            rank.push_back(1);
            parent.push_back(i);
        }
    }
    int find(int son) {
        int root = son;
        while (root != parent[root]) {
            root = parent[root];
        }
        
        int temp = son;
        while (son != parent[son]) {
            temp = parent[son];
            parent[son] = root;
            son = temp;
        }
        
        return root;
    }
    void merge(int son1, int son2) {
        int root1 = find(son1);
        int root2 = find(son2);
        
        if (root1 != root2) {
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;    
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                rank[root1] += 1;
            }
            
            count -= 1;
        }
    }
    int getCnt(void) {
        return count;
    }
private:
    int count;
    vector<int> rank;
    vector<int> parent;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        mergeFind mf(M.size());
        
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M.size(); ++j) {
                if (M[i][j] == 1) {
                    mf.merge(i, j);
                }
            }
        }
        
        return mf.getCnt();
    }
};
```