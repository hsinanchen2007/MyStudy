大致思路就是根据字母出现的顺序先构造出图来，
然后进行一下拓扑排序就可以了

构造图的过程就是遍历字符串，
找到第i个和第i+1个字符串第一对不同的字母，然后建立一对关系。

建立完图排一个拓扑序就ok了。

```c
class Solution {
private:
    int cnt;
    vector<int> in_degree;
    vector<vector<int>> graph;
    
    void init_graph(vector<string>& words) {
        for (char c : words[0]) 
            if (in_degree[c - 'a'] == -1) ++cnt,in_degree[c - 'a'] = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            for (char c : words[i + 1]) 
                if (in_degree[c - 'a'] == -1) ++cnt,in_degree[c - 'a'] = 0;
            for (int j = 0; j < words[i].size(); j++) {
                char from = words[i][j], to = words[i + 1][j];
                if (from == to) continue;
                graph[from - 'a'].push_back(to - 'a');
                ++in_degree[to - 'a'];
                break;
            }
        }
    }
    
    string topology_sort() {
        string ans = "";
        
        queue<int> q;
        for (int i = 0; i < in_degree.size(); i++) {
            if (in_degree[i] > 0 || in_degree[i] == -1) continue;
            q.push(i);
            ans += (i + 'a');
        }
        
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                int from = q.front(); q.pop();
                for (int to : graph[from]) {
                    if (in_degree[to] == 1) {
                        q.push(to);
                        ans += (to + 'a');
                    }
                    --in_degree[to];
                }
            }
        }
        
        return ans.size() == cnt ? ans : "";
    }
    
public:
    Solution():cnt (0), in_degree(26, -1), graph(26) {}
    
    string alienOrder(vector<string>& words) {
        
        init_graph(words);
        
        return topology_sort();
    }
};
```



执行用时 :4 ms , 在所有 C++ 提交中击败了93.18%的用户
内存消耗 :9 MB , 在所有 C++ 提交中击败了100.00%的用户