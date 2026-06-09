### 解题思路
c++

### 代码

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        sort(intervals.begin(), intervals.end(), CompareVec);
        //for(int i = 0; i < intervals.size(); ++i) {
        //    cout<<intervals[i][0]<<endl;
        //}
        for(int i = 0; i < intervals.size(); ++i) {
            if (res.empty()) {
                res.push_back(intervals[i]);
            } else {
                int j = 0;
                for(; j < res.size(); ++j) {
                    if (isInterval(res[j], intervals[i]) == false) {
                        int end = max(res[j][1], intervals[i][1]);
                        res[j][1] = end;
                        break;
                    }
                }
                if (j == res.size()) {
                    res.push_back(intervals[i]);
                }
            }
        }
        return res.size();
    }

    static bool CompareVec(vector<int>& v1, vector<int>& v2) {
        if (v1[0] < v2[0]) {
            return true;
        } else if (v1[0] > v2[0]) {
            return false;
        } else {
            return v1[1] < v2[1];
        }
    }

    bool isInterval(vector<int>& v1, vector<int>& v2) {
        //cout<<v1[0]<<" "<<v1[1]<<" "<<v2[0]<<" "<<v2[1]<<endl;
        
        if (v1[1] > v2[0]) {
            return true;
        } 
        return false;
    }
};
```