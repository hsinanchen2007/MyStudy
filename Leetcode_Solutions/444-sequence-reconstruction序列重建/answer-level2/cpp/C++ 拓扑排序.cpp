```
// 解法1: 拓扑排序
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, unordered_set<int> > graph;
        unordered_map<int, int> indegree;
        for (auto s : seqs) {
            if (s.empty())
                continue;
            int ind = s[0];
            indegree[ind] += 0;
            for (int i = 1; i < s.size(); ++i) {
                if (graph[ind].find(s[i]) == graph[ind].end()) {
                    graph[ind].insert(s[i]);
                    ++indegree[s[i]];
                }
                ind = s[i];
            }
        }
        if (org.size() != indegree.size())
            return false;
        for (auto x : org)
            if (indegree.count(x) == 0)
                return false;
        queue<int> q;
        unordered_set<int> seen;
        for (auto& p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
                seen.insert(p.first);
            }
        }
        vector<int> nodes;
        while (!q.empty()) {
            if (q.size() > 1)
                return false;
            int k = q.front();
            nodes.push_back(k);
            q.pop();
            for (auto x : graph[k]) {
                --indegree[x];
                if (indegree[x] == 0 && seen.find(x) == seen.end())
                    q.push(x);
            }
        }
        return nodes.size() == org.size();
    }
};

// 解法2: 顺序相邻对检查
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<int> pos(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pos[org[i]] = i;
        }
        vector<bool> seen_pair(n + 1, false);
        vector<bool> seen_node(n + 1, false);
        bool find_num = false;
        for (auto& seq : seqs) {
            if (seq.empty())
                continue;
            int k = seq[0];
            if (k <= 0 || k > n)
                return false;
            seen_node[k] = true;
            for (int i = 1; i < seq.size(); ++i) {
                if (seq[i] <= 0 || seq[i] > n || pos[seq[i]] <= pos[k])
                    return false;
                seen_node[seq[i]] = true;
                if (pos[seq[i]] - pos[k] == 1 && !seen_pair[k])
                    seen_pair[k] = true;
                k = seq[i];
            }
        }
        int pairs = 0;
        for (int i = 1; i <= n; ++i) {
            if (!seen_node[i])
                return false;
            if (seen_pair[i])
                ++pairs;
        }
        return pairs == n - 1;
    }
};
```
