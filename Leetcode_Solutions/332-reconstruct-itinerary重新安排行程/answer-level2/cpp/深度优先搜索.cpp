对于一个机场站点，有一系列可达的下一个机场，将这些机场按照字典序排序，然后深度搜索即可。

为避免重复使用同一张机票，搜索时需记录已使用过的机票。

搜索终止条件：如果有n张机票，那么路径的长度一定是n+1。

```
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 两个机场间可能有多张机票，所以value用int来计数
        // map保证value有序，可以保证第一个搜索结果即为最终结果
        map<string, map<string, int>> m, vis;
        for(auto t: tickets) m[t[0]][t[1]]++;
        vector<string> res, cur;
        // 添加起始点
        cur.push_back("JFK");
        dfs(m, vis, cur, tickets.size()+1, res);
        return res;
    }
    void dfs(map<string, map<string, int>>& m, map<string, map<string, int>>& vis, vector<string>& cur, int n, vector<string>& res) {
        // 如果已经找到一个结果，直接返回
        if(res.size()==n) return;
        if(cur.size()==n) {
            res = cur;
            return;
        }
        // 没有以当前机场为起点的机票，中止搜索
        if(m.find(cur.back())==m.end()) return;
        // 遍历
        for(auto it: m[cur.back()]) {
            string stop = it.first;
            // 根据机票数量判断是否可以继续搜索
            if(vis[cur.back()][stop]==it.second) continue;
            vis[cur.back()][stop]++;
            cur.push_back(stop);
            dfs(m, vis, cur, n, res);
            cur.pop_back();
            vis[cur.back()][stop]--;
            // 如果已经找到一个结果，直接返回
            if(res.size()==n) return;
        }
    }
};
```
