整体思路：
遍历原数组，如果当前区间和新区间没有交集，则直接存入答案；
如果有交集，便和新区间合并，更新新区间的左右边界；
如果当前区间和新区间无交集且大于新区间，则新区间和后面所有的区间都可存入答案。

1.如果newInterval[0] > intervals[i][1]，此区间和新区间无交集，直接存入答案
2.如果newInterval[1] < intervals[i][0]，从此区间起，所有区间都和新区间无交集，所有区间存入答案
3.此区间和新区间有交集，合并区间
newInterval[0] = min(newInterval[0], intervals[i][0]);  
newInterval[1] = max(newInterval[1], intervals[i][1]);

注意：如果新区间大于所有区间，不会在循环中存入答案，所以应有一个flag记录新区间是否存入答案

```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool flag = false;        //新区间是否放置进答案
        for(int i = 0; i < intervals.size(); i++){
            if(newInterval[0] > intervals[i][1]){
                ans.push_back(intervals[i]);
                continue;
            }
            if(newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);
                flag = !flag;
                for(; i < intervals.size(); i++)
                    ans.push_back(intervals[i]);
                break;
            }
            newInterval[0] = min(newInterval[0], intervals[i][0]);  //区间合并
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        if(!flag)
            ans.push_back(newInterval);
        
        return ans;
    }
};
```
