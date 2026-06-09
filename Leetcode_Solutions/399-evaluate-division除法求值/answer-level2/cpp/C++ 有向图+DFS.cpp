### 解题思路
一开始想要把所有变量都表示为同一个变量的倍数关系，进而想到了有向图

a->b的权重n表示a*n = b，且有b->a的权重为1/n

则queries里的[a,b]就是从b到a的任意一条路径的权重之积

寻找路径可以用dfs

### 代码

```cpp
class Solution {
public:
    bool find = false;
    //寻找从start到end的路径，当前所在节点为temp，ans记录当前路径的权重之积
    void dfs(const string& start, const string& end, string& temp,  unordered_map<string, vector<pair<string, double>>>& g, double& ans, unordered_set<string>& visited){
        if (find) return;
        if (temp == end){
            find = true;
            return;
        }
        string back = temp;
        for(auto it = g[temp].begin(); it != g[temp].end(); it++){
            if(visited.find(it->first) == visited.end()){
                visited.insert(it->first);
                ans *= it->second;
                temp = it->first;
                dfs(start, end, temp, g, ans, visited);
                if(find) return;
                temp = back;
                ans /= it->second;
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g;
        for(int i = 0; i < equations.size(); i++){//构造有向图
            g[equations[i][0]].push_back(make_pair(equations[i][1], 1/values[i]));
            g[equations[i][1]].push_back(make_pair(equations[i][0], values[i]));
        }
        vector<double> ans(queries.size());
        for(int i = 0; i < queries.size(); i++){
            string start = queries[i][1];
            string end = queries[i][0];
            if(g.find(start) == g.end() || g.find(end) == g.end())//起始点有一个不在图中
                ans[i] = -1.0;
            else if(start == end)
                ans[i] = 1.0;
            else{
                unordered_set<string> visited;
                visited.insert(start);
                ans[i] = 1.0;
                find = false;
                dfs(start, end, start, g, ans[i], visited);
                if(!find)//非连通图可能存在起始点间不存在路径的情况
                    ans[i] = -1.0;
            }
        }
        return ans;
    }
};
```