### 解题思路

res.push_back()
res.back()[1]，res.back()[0]/取res最后一个数组
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return{};
        int n=intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());//按第一个数排序
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++){
        if(res.back()[1]>=intervals[i][0])
            res.back()[1]=max(res.back()[1],intervals[i][1]);
            else{
            res.push_back(intervals[i]);
         }
        }
        return res;
    }
};
```