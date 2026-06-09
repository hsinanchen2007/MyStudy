```
class Solution {
public:
    static bool cmpFunc(vector<int> a, vector<int> b)
    {
        return a[0]<b[0];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size()<=0)
        {
            return true;
        }
        sort(intervals.begin(), intervals.end(), cmpFunc);
        
        for (int i=0; i<intervals.size()-1; i++)
        {
            if (intervals[i][1] > intervals[i+1][0])
            {
                return false;
            }
        }
        return true;            
    }
};
```
