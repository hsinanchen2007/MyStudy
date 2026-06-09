### 思路
参考[Grandyang](https://www.cnblogs.com/grandyang/p/5880133.html)

### 代码

```cpp
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            ump[equations[i][0]][equations[i][1]] = values[i];
            ump[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        for (auto query : queries) {
            unordered_set<string> visited;
            double t = helper(query[0], query[1], visited);
            res.push_back((t > 0.0) ? t : -1);
        }
        return res;
    }

    double helper(string up, string down, unordered_set<string> &visited) {
        if (ump[up].count(down)) return ump[up][down];
        for (auto a : ump[up]) {
            if (visited.count(a.first) > 0) continue;
            visited.insert(a.first);
            double t = helper(a.first, down, visited);
            if (t > 0.0) return t * a.second;
        }
        return -1.0;
    }
private:
    unordered_map<string, unordered_map<string, double>> ump;
};
```