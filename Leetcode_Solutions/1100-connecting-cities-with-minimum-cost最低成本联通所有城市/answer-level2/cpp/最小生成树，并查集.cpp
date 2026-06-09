### 解题思路
参考了其他同学的代码，对merge做了一些改造

### 代码

```cpp
class mergeFind {
public:
    mergeFind(int n) {
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }
    int find(int son) {
        if (parent[son] != son) {
            parent[son] = find(parent[son]);
        }
        
        return parent[son];
    }
    int merge(int a, int b) {
        int roota = find(a);
        int rootb = find(b);
        if (roota == rootb) {
            return -1;
        }
        
        if (rank[roota] > rank[rootb]) {
            parent[rootb] = roota;
            rank[roota] += rank[rootb];
        } else {
            parent[roota] = rootb;
            rank[rootb] += rank[roota];
        }
        
        return max(rank[roota], rank[rootb]);
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        if (N == 1) {
            return 0;
        }
        if (N > connections.size() + 1) {
            return -1;
        }
        
        sort(connections.begin(), connections.end(), [](vector<int>& a, vector<int>& b){return a[2] < b[2];});
        
        mergeFind mf(N);
        int total = 0, result = 0;
        for (auto each : connections) {
            int rtn = mf.merge(each[0] - 1, each[1] - 1);
            if (rtn == -1) {
                continue;
            } else {
                total = rtn;
            }
            
            result += each[2];
            if (total == N) {
                return result;
            }
        }
        
        return -1;
    }
};
```