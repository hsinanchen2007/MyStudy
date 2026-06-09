```
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> diff;
        int m = costs.size();
        
        //sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) {return *(a.begin()+i) < *(b.begin() + i); });
        //根据A-B的差值排序
        sort(costs.begin(),costs.end(),[](vector<int> &a, vector<int> &b) {return a[0]-a[1] < b[0]-b[1];});
        
        int res = 0;
        for(int i = 0;i < m;i++){
            //cout<<costs[i][0]<<"  "<<costs[i][1]<<endl;
            if(i<m/2)
                res=res+costs[i][0];
            else
                res=res+costs[i][1];
        }
        
        return res;
    }
};
```
