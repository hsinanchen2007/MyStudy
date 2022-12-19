```
#include <algorithm>
using namespace std;

bool compare(const vector<int>& vec1, const vector<int>& vec2)
{
    return vec1.front() < vec2.front();
}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> meet;
        for (auto s : intervals) {
            int flag = 0;
            for (auto iter = meet.begin(); iter != meet.end(); ++iter) {
                if (s.front() >= *iter) {
                    *iter = s.back();
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                meet.push_back(s.back());
            }
        }
        return meet.size();
    }
};
```

