查并集模板题目

```
class Solution {
public:
    
    int par[1001];
    int rankB[1001];

    void initPar(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            rankB[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    void unin(int p, int q) {
        int parP = find(p);
        int parQ = find(q);
        if (parP == parQ) {
            return;
        }
        if (rankB[parP] > rankB[parQ]) {
            par[parQ] = parP;
        } else {
            par[parP] = parQ;
            if (rankB[parQ] == rankB[parP]) {
                rankB[parQ] += 1;
            }
        }
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        initPar(1000);
        for (auto edge : edges) {
            int first = edge[0];
            int second = edge[1];
            if (find(first) == find(second)) {
                return edge;
            } else {
                unin(first, second);
            }
        }
        return {};
    }
};
```