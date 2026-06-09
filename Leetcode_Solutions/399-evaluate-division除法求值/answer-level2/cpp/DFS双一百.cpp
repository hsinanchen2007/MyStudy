```
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> m;
        vector<double> res;
        unordered_set<string> vis;
        for(int i=0;i<equations.size();++i){
            m[equations[i][0]][equations[i][1]]=values[i];
            m[equations[i][1]][equations[i][0]]=1.0/values[i];
        }
        for(auto i:queries){
            string u=i[0],v=i[1];
            function<double(string)> dfs=[&](string u){
                vis.insert(u);
                if(m[u].find(v)!=m[u].end()) return m[u][v];
                for(auto&& [k,_v]:m[u]){
                    if(vis.count(k)) continue;
                    double weight=dfs(k);
                    if(weight!=-1){
                        m[u][v]=weight*m[u][k];
                        m[v][u]=1.0/(weight*m[u][k]);
                        return m[u][v];
                    }
                }
                return (double)-1;
            };
            if(m.find(u)==m.end()||m.find(v)==m.end()){
                res.push_back(-1);continue;
            }
            double tmp=dfs(u);
            res.push_back(tmp!=-1?tmp:-1);
            vis.clear();
        }
        return res;
    }
};

```
![image.png](https://pic.leetcode-cn.com/28ef61e0e76019d4a579652970c40747b0c48aad7fd6eae1564a3d993e94a93e-image.png)
