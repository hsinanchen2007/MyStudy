主要思路还是前面大佬的，这里只是改下细节，希望能好懂一点点。

```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0){
            return res;
        }
        auto compare = [](vector<int>& v1, vector<int>& v2){ return v1[0] < v2[0];};
        sort(intervals.begin(), intervals.end(), compare);  // 按区间的start排序
        vector<int> cur(intervals[0]);  // 从第0个开始
        for(int i = 1; i < intervals.size(); i++){
            if(cur[1] >= intervals[i][0]){ 
                cur[1] = max(cur[1], intervals[i][1]);  // 区间有交集，则合并，直接修改区间的最大值即可
            }else{
                res.push_back(cur);  // 当前计算的区间已经结束，存到结果集中
                cur = vector<int>(intervals[i]);
            }
        }
        res.push_back(cur); // 把最后的计算结果也存到结果集中
        return res;
    }
};
```
