### 解题思路
一次遍历，找到需要合并的区间替换，没有交集的部分保留即可。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int r;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][1] < newInterval[0]){
                ret.push_back(intervals[i]);
            }
            else{
                if(intervals[i][0] <= newInterval[0]){
                    newInterval[0] = intervals[i][0];
                }
                for(; i < intervals.size(); i++){
                    if(intervals[i][1] > newInterval[1]){
                        if(intervals[i][0] <= newInterval[1]){
                            newInterval[1] = intervals[i][1];
                            i++;
                        }
                        ret.push_back(newInterval);
                        ret.insert(ret.end(), intervals.begin() + i, intervals.end());
                        return ret;
                    }
                }
            }
        }
        ret.push_back(newInterval);
        return ret;
    }
};
```