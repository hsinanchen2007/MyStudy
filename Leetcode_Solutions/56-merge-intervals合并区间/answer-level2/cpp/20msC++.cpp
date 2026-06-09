### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        for(int i = 0; i < intervals.size(); i++){
            vector<int> tmp = intervals[i];
            int j = i+1;
            while(j < intervals.size() && tmp[1] >= intervals[j][0]){
                if(tmp[1] >= intervals[j][0] && tmp[1] < intervals[j][1]){
                    tmp[1] = intervals[j][1];
                }
                j++;
                i++;
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```