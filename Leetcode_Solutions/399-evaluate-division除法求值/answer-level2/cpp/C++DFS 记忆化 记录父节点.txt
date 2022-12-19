算法思想：
1. 建立所有操作数的带权重的有向图;
2. 找到一条从被除数到除数的路径;
3. 把路径上的权值依次相乘。

```
unordered_map<string, unordered_map<string, double>> adjW;

double calcOne(vector<string>& query) {
    if (adjW.find(query[0]) == adjW.end()) {
        return -1.0;
    }
    if (adjW[query[0]].find(query[1]) != adjW[query[0]].end()) {
        return adjW[query[0]][query[1]];
    }
    
    stack<string> calcStack;
    map<string, string> parent;
    map<string, int> nodeColor;
    calcStack.push(query[0]);
    nodeColor[query[0]] = 1;
    bool found = false;
    while (!calcStack.empty()) {
        string curr = calcStack.top();
        if (nodeColor[curr] == 1) {
            for (auto nbr : adjW[curr]) {
                if (nodeColor.find(nbr.first) == nodeColor.end()) {
                    parent[nbr.first] = curr;
                    calcStack.push(nbr.first);
                    nodeColor[nbr.first] = 1;
                }
            }
            nodeColor[curr] = 2;
        } else if (nodeColor[curr] == 2) {
            cout << "now pop -> " << curr << ". " << endl;
            if (curr == query[1]) {
                found = true;
                cout << "found." << endl;
                break;
            }
            calcStack.pop();
        }
    }
    if (found) {
        double ans = 1.0;
        string curr = query[1];
        while (parent.find(curr) != parent.end()) {
            cout << "curr: " << curr << ", parent: " << parent[curr] << endl;
            ans *= adjW[parent[curr]][curr];
            if (parent[curr] == query[0]) {
                break;
            }
            curr = parent[curr];
        }
        adjW[query[0]][query[1]] = ans;
        return ans;
    }
    
    return -1.0;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    
    for (int i = 0; i < equations.size(); ++i) {
        adjW[equations[i][0]][equations[i][1]] = values[i];
        adjW[equations[i][1]][equations[i][0]] = 1 / values[i];
    }
    
    vector<double> ans(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
        ans[i] = calcOne(queries[i]);
    }
    
    return ans;
}
```

![image.png](https://pic.leetcode-cn.com/0663e220708cfa93c8ad75d8ba8c5820be8979828eff5c3bfb013a34aa20c53b-image.png)

