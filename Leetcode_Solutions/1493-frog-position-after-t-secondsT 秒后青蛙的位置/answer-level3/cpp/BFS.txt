```
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& es, int t, int tt) {
        vector<vector<int>> g(n+1);
        for(vector<int>&v:es){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        vector<int> m(n+1);
        double cc=1.0;
        queue<pair<int,double>> q;
        q.push({1,1.0});m[1]=1;int cur=0;
        while(!q.empty()&&cur<=t){
            int sz=q.size();
            while(sz--){
                auto pp=q.front();q.pop();
                int ci=pp.first;double pi=pp.second;
                if(ci==tt){
                    int ct=0;
                    for(int &nb:g[ci])
                        if(m[nb]==0)
                            ct++;
                    if(ct>0)
                        return cur==t?pi:0;
                    return pi;
                }
                int ct=0;
                    for(int &nb:g[ci])
                        if(m[nb]==0)
                            ct++;
                for(int &nb:g[ci]){
                    if(m[nb]==0){
                        m[nb]=1;
                        q.push({nb,pi/ct});
                    }
                }
            }
            cur++;
        }
        return 0;
    }
};
```
