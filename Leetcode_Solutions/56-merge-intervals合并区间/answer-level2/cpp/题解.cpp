### 解题思路
先将intervals第一维第一个数进行 升序排序，之后将第一个区间作为开始，判断下一个区间的第一个数与前一区间的第二个数的大小关系，如果前一区间第二个数大于当前区间第一个数，则将他们合并。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1)
        return intervals;
    vector<vector<int>>output;
    std::sort(intervals.begin(),intervals.end(),[&, this](vector<int>&v1,vector<int>&v2){return v1[0] < v2[0];});

    for(int i = 0; i < intervals.size(); i++){
        vector<int> temp = intervals[i];
        while(i + 1 < intervals.size() && temp[1] >= intervals[i + 1][0]){
            i++;
            temp[1] = max(temp[1], intervals[i][1]);
        }
        output.push_back(temp);
    }
    return output;
    }
};
```