最小生成树算法
1，增加虚拟节点0，并将其与剩余所有的点连起来，边的权重为在某个点挖井的耗费
2，利用map结构进行最小生成树的搜索，对已经进入到最小生成树中的点之间形成的边进行切割，以减少后续的搜索数据量
```
class Solution {
public:
    int MSTPath(map<int, set<vector<int>>>& edges, const int& N) {
        int res = 0;
        vector<int> used(N, false);
        used[0] = true;
        for (int i = 1; i < N; ++i) {
            int min_weight =INT_MAX;
            int srcid = -1;
            int dstid = -1;
            for (auto it = edges.begin(); it != edges.end();) {
                for (auto inner_it = (it->second).begin(); inner_it != (it->second).end();) {
                    int _src = inner_it->at(0);
                    int _dst = inner_it->at(1);
                    if (used[_src] && used[_dst]) {
                        it->second.erase(inner_it++); // erase the edge whose srcid and dstid both are used;
                        continue;
                    }
                    if (!used[_src] && !used[_dst]) {
                        ++inner_it;
                        continue;
                    }
                    if (it->first < min_weight) {
                        srcid = _src;
                        dstid = _dst;
                        min_weight = it->first;
                        break;
                    }
                    ++inner_it;
                }
                if (srcid != -1) {
                    used[srcid] = true;
                    used[dstid] = true;
                    res += min_weight;
                    break;
                }
                if ((it->second).empty()) {
                    edges.erase(it++); // erase the weight whose responding edges have been empty
                } else {
                    ++it;
                }
            }
        }
        return res;
    }
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // key is weight (the cost), values is the edges whose weight equals to the key
        // format like: [weight: [(srcid1, dstid1), (srcid2, dstid2), ...], ...]
        map<int, set<vector<int>>> edges; 
        // add virtual node 0 and its edges with every real nodes
        for (int i = 0; i < wells.size(); ++i)
            edges[wells[i]].insert({0, i + 1}); 
        for (auto e : pipes)
            edges[e[2]].insert({e[0], e[1]});
        const int N = wells.size() + 1;
        return MSTPath(edges, N);
    }
};
```
