这里记录目前看到的三种比较优雅通用的解法，全部来源于评论区和题解区。

### 方法一：Floyd

取自 [@onesilverbullet](/u/onesilverbullet/) 的[题解](https://leetcode-cn.com/problems/evaluate-division/solution/floydde-yi-ge-jian-dan-bian-chong-by-onesilverbull/)，我按照自己的理解：

```
struct Value {
    int status;
    double val;
    Value(): status(0), val(0) {}
    Value(int s, double v) : status(s), val(v) {}
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {      
        unordered_map<string, int> store;
        int n = 0;
        for (auto e : equations) {
            if (store.find(e[0]) == store.end())
                store[e[0]] = n++;
            if (store.find(e[1]) == store.end())
                store[e[1]] = n++;
        }

        vector<vector<Value>> graph(n, vector<Value>(n, Value()));
        for (int i = 0; i < equations.size(); ++i) {
            int ia = store[equations[i][0]];
            int ib = store[equations[i][1]];
            graph[ia][ib] = Value(1, values[i]);
            graph[ib][ia] = Value(1, 1/values[i]);
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (graph[i][j].status == 0 && graph[i][k].status == 1 && graph[k][j].status == 1) {
                        graph[i][j] = Value(1, graph[i][k].val * graph[k][j].val);
                    }
                }
            }
        }
        
        vector<double> res;
        for (auto q : queries) {
            if (store.find(q[0]) == store.end() || store.find(q[1]) == store.end()) {
                res.push_back(-1);
                continue;
            } 
            int ia = store[q[0]];
            int ib = store[q[1]];
            double r = graph[ia][ib].status == 1 ? graph[ia][ib].val : -1;
            res. push_back(r);
        }
        return res;
    }
};
```

### 方法二：dfs 和 bfs

主要分为两步：
1. build 构造初始化图
1. dfs 或者 bfs 进行遍历


```
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        auto graph = build(equations, values);
           
        vector<double> res;  
        for (auto q : queries) {
            set<string> visited;
            bool found = false;
            //double r = bfs(graph, visited, q[0], q[1], found);
            double r = dfs(graph, visited, q[0], q[1], found);
            if (found) {
                res.push_back(r);
                graph[q[0]][q[1]] = r;
                graph[q[1]][q[0]] = 1 / r;
            } else {
                res.push_back(-1);
            }
        }
      
        return res;
    }

    unordered_map<string, unordered_map<string, double>> build(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, unordered_map<string, double>> m;
        for (int i = 0; i < equations.size(); ++i) {
            vector<string> eqa = equations[i];
            string a = eqa[0];
            string b = eqa[1];
            double v = values[i];
            if (m.find(a) == m.end()) {
                m[a] = unordered_map<string, double>{{b, v}};
            } else {
                m[a][b] = v;
            }
            if (m.find(b) == m.end()) {
                m[b] = unordered_map<string, double>{{a, 1 /v}};
            } else {
                m[b][a] = 1 / v;
            }
        }
        return m;
    }

    double bfs(unordered_map<string, unordered_map<string, double>>& g, set<string> visited, string begin, string end, bool& found) {
        if (g.find(begin) == g.end() || g.find(end) == g.end()) {
            found = false;
            return -1;
        }
        queue<pair<string, double>> q;
        q.push(make_pair(begin, 1));
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (visited.find(cur.first) != visited.end()) {
                continue;
            }
            if (cur.first == end) {
                found = true;
                return cur.second;
            }
            visited.insert(cur.first);
            for (auto it : g[cur.first]) {
                q.push(make_pair(it.first, cur.second * it.second));
            }
        }
        found = false;
        return -1;
    }
  
    double dfs(unordered_map<string, unordered_map<string, double>>& g, set<string> visited, string begin, string end, bool& found) {
        if (g.find(begin) == g.end() || g.find(end) == g.end()) {
            found = false;
            return -1;
        }
        if (visited.find(begin) != visited.end()) {
            found = false;
            return -1;
        }
        if (g[begin].find(end) != g[begin].end()) {
            found = true;
            return g[begin][end];
        }
        visited.insert(begin);
        for (auto it : g[begin]) {
            double r = dfs(g, visited, it.first, end, found);
            if (found) {
                double res = r * it.second;
                return res;
            }
        }
        visited.erase(begin);
        found = false;
        return -1;
    }
};
```

### 方法三：并查集

参考 [@musa_geek](/u/musa_geek/) 的 [题解](https://leetcode-cn.com/problems/evaluate-division/solution/c-can-kao-xiao-xu-da-ge-de-xie-fa-bing-qie-zuo-lia/)：

```
struct Node {
    double value;
    Node* parent;
    Node() : parent(this) {}
    Node(double v) : value(v), parent(this) {}
};

class Solution {
    unordered_map<string, Node*> m;

    Node* find(Node* n) {
        if (n->parent != n) {
            n->parent = find(n->parent);
        }
        return n->parent;
    }
   
    void merge(Node* n1, Node* n2, double val) {
        Node* p1 = find(n1);
        Node* p2 = find(n2);
        double ratio = n2->value * val / n1->value;
        for (auto it : m) {
            if (find(it.second) == p1) {
                it.second->value *= ratio;
            }
        } 
        p1->parent = p2;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            if (m.find(a) == m.end()) m[a] = new Node(values[i]);
            if (m.find(b) == m.end()) m[b] = new Node(1.0);
            merge(m[a], m[b], values[i]);
        }
        vector<double> res;
        for (auto q : queries) {
            if (m.find(q[0]) == m.end() || m.find(q[1]) == m.end() || find(m[q[0]]) != find(m[q[1]])) {
                res.push_back(-1);
            } else {
                res.push_back(m[q[0]]->value / m[q[1]]->value);
            }
        }
        return res;
    }
};
```

上面3种方法都很优雅，并且都是很通用的方法，都需要理解、掌握。

再次感谢文中提到的同学，受益匪浅，谢谢。