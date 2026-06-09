```
class Solution {
public:
    struct Node {
        string user;
        string web;
        int ts;
        bool operator < (const Node& other) {
            return this->ts < other.ts;
        }
        Node(const string& _user, const string& _web, int _ts) : user{_user}, web(_web), ts(_ts) {};
    };
    bool less(map<int, string>& m, const vector<int>& v1, const vector<int>& v2) {
        for (int i = 0; i < v1.size(); ++i) {
            if (m[v1[i]] < m[v2[i]]) return true;
            if (m[v1[i]] > m[v2[i]]) return false;
        }
        return false;
    }
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int N = username.size();
        vector<Node> nodes;
        map<string, int> web2int;
        map<int, string> int2web;
        for (int i = 0; i < N; ++i) {
            nodes.push_back(Node(username[i], website[i], timestamp[i]));
            if (!web2int.count(website[i])) {
                web2int[website[i]] = web2int.size();
                int2web[int2web.size()] = website[i];
            }
        }
        sort(nodes.begin(), nodes.end());
        map<vector<int>, set<string> > m;
        for (int i = 0; i < N - 2; ++i) {
            int n1 = web2int[nodes[i].web];
            for (int j = i + 1; j < N - 1; ++j) {
                if (nodes[i].user != nodes[j].user) continue;
                int n2 = web2int[nodes[j].web];
                for (int k = j + 1; k < N; ++k) {
                    if (nodes[j].user != nodes[k].user) continue;
                    int n3 = web2int[nodes[k].web];
                    m[{n1, n2, n3}].insert(nodes[i].user);
                }
            }
        }
        int mx = 0;
        vector<int> mx_path;
        for (auto& p : m) {
            if (p.second.size() > mx) {
                mx = p.second.size();
                mx_path = p.first;
            } else if (p.second.size() == mx) {
                if (less(int2web, p.first, mx_path)) {
                    mx_path = p.first;
                }
            }
        }
        vector<string> res;
        for (int i = 0; i < mx_path.size(); ++i) {
            res.push_back(int2web[mx_path[i]]);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/57e89b1337ae961263c8d7a8d32704b2a26a7e0f9d44280396342353e7b20e0d-image.png)
