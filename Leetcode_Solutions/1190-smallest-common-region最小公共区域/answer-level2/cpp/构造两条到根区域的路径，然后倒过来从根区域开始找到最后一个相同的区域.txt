```c++
class Solution {
public:
    void DFS(vector<string> &p, unordered_map<string, string> &m, string &r){
        p.push_back(r);
        if(m.count(r) != 0) DFS(p, m, m[r]);
        else return;
    }
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> m;
        for(auto &x:regions){
            string p=x[0];
            for(int i = 1;i < x.size(); ++i){
                m[x[i]]=p;
            }
        }
        vector<string> p1, p2;
        int i, j;
        DFS(p1, m, region1), DFS(p2, m, region2);
        for(i=p1.size()-1,j=p2.size()-1;i>=0&&j>=0&&p1[i] == p2[j];--i,--j);  
        return p1[i+1];
    }
};
```
