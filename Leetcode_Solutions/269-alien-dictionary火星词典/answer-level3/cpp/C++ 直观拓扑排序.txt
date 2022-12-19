```
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty())
            return "";
        const int N = 26;
        // construct graph part
        vector<vector<int> > m(N, vector<int>(N, 0)); // m is the adjacency graph
        vector<int> indegree(N, 0);
        vector<int> exists(N, false);
        int count = 0;
        string prev = words[0];
        for (auto c : prev) 
            exists[c - 'a'] = true;
        for (int i = 1; i < words.size(); ++i) {
            if (words[i] == prev) continue;
            string curr = words[i];
            for (auto c : curr)
                exists[c - 'a'] = true;
            int j = 0;
            while (j < curr.size() && j < prev.size() && curr[j] == prev[j]) ++j;
            if (j < curr.size() && j < prev.size()) {
                ++m[prev[j] - 'a'][curr[j] - 'a']; // add edge
                ++indegree[curr[j] - 'a']; // add in degree
            }
            prev = curr;
        }
        // count exists char number
        for (auto x : exists)
            count += x;
        
        // topology sort part
        queue<int> q;
        vector<bool> seen(N, false);
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0 && exists[i]) {
                q.push(i);
                seen[i] = true;
            }
        }
        string res;
        while (!q.empty()) {
            int k = q.front();
            res += char(k + 'a');
            q.pop();
            for (int i = 0; i < m[k].size(); ++i) {
                if (!exists[i]) continue;
                indegree[i] -= m[k][i];
                if (!seen[i] && indegree[i] == 0) {
                    q.push(i);
                    seen[i] = true;
                }
            }
        }
        // check if there exists a cycle
        if (res.size() != count)
            return "";
        return res;
    }
};
```
