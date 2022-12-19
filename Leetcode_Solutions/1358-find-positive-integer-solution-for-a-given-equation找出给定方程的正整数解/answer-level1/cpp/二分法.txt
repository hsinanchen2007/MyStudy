```
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for(int i=1;i<=1000;++i)
        {
           if( auto y=solu(customfunction,i,z))res.push_back({i,y});
            
        }
        return res;
        
    }
    int solu(CustomFunction&c,int x,int z)
    {
        int io=1,hi=1000,mi;
        while(io<=hi)
        {
            mi=(io+hi)/2;
            if(c.f(x,mi)==z) return mi;
            else if(c.f(x,mi)<z)io=mi+1;
            else hi=mi-1;
        }
        return 0;
    }
};
```
# x从1到1000遍历，对每一个x,用二分法查找对应的y.
