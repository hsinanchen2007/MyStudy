

```
class Solution {
public:
    vector<int>ans;
    map<int,int>m[4];
    set<pair<int, int>>lam;
    inline void add(int i, int a, int b)
    {
        if(!m[i].count(a)) m[i][a] = b;
        else m[i][a] += b;
    }
    inline bool test(int i, int a)
    {
        if(m[i].count(a) && m[i][a] != 0)  return true;
        return false;
    }
   
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        
        for(auto x:lamps)
        {
            add(0, x[0], 1);
            add(1, x[1], 1);
            add(2, x[0] - x[1], 1);
            add(3, x[0] + x[1], 1);
            lam.insert(make_pair(x[0],x[1]));
        }
        for(auto q: queries)
        {
            if(test(0, q[0]) || test(1, q[1]) || test(2, q[0]-q[1]) || test(3, q[0]+q[1])) 
                ans.push_back(1);
            else ans.push_back(0);
            for(int i = -1;i<2;i++)
                for(int j =-1;j<2;j++)
                {
                    int x = q[0] + i;
                    int y = q[1] + j;
                    auto i = make_pair(x,y);
                    if(lam.find(i) == lam.end()) continue;
                    add(0,x, -1);
                    add(1,y, -1);
                    add(2,x-y, -1);
                    add(3,x+y, -1);
                    //printf("%d\n", lam.size());
                    lam.erase(i);
                }
        }
        return ans;
    }
};
```
