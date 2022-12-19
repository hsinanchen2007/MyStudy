```
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res=0;
        int n=stations.size();
        priority_queue<int> tmp;
        for(int i=0;i<n;++i)
        {
            while(startFuel<stations[i][0]&&!tmp.empty())
            {
                startFuel+=tmp.top();
                tmp.pop();
                res++;
            }
            if(startFuel>=target)
            {
                return res;
            }
            else if(startFuel>=stations[i][0])
            {
                tmp.push(stations[i][1]);
            }
            else
            {
                return -1;
            }
        }
        while(startFuel<target&&!tmp.empty())
        {
            startFuel+=tmp.top();
            tmp.pop();
            res++;
        }
        if(startFuel>=target)
        {
            return res;
        }
        else
        {
            return -1;
        }
    }
};
```
