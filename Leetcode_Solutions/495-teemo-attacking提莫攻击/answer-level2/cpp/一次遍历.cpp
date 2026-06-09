``` C++
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;
        int res=duration;
        for(int i=1;i<timeSeries.size();i++)
        {
            //前后差值大于duration，加duration,否则加前后值之差
            if(timeSeries[i]-timeSeries[i-1]>duration)
                res+=duration;
            else
                res+=timeSeries[i]-timeSeries[i-1];
        }
        return res;
    }
};
```