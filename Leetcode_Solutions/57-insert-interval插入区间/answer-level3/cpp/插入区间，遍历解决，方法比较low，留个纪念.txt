### 解题思路
区间无重叠
- 'intervals[i][1] < newInterval[0]' 此时说明第i个区间小于新区间，所以直接将第i个区间加入到结果中
- 'intervals[i][0] > newInterval[1]' 此时说明第i个区间大于新区间，所以先将新区间加入结果，在顺序遍历后面的区间依次加入到结果中
区间有重叠
使用curmin 和 curmax 来标志所需要合并的区间的左右端点。
curmin 初始化为 newInterval[0] intervals[i][0]的最小值
curmax 初始化为 newInterval[1] 或 intervals[i][1]
区间合并的条件 newInterval[1] >= intervals[i][0]

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        if(intervals.size()==0){ret.push_back(newInterval);return ret;}
        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i][1] < newInterval[0]) //无重叠
            {
                ret.push_back({intervals[i][0],intervals[i][1]}); continue;
            }
            if(intervals[i][0] > newInterval[1]) //无重叠
            {
                ret.push_back({newInterval[0],newInterval[1]});
                for(;i<intervals.size(); i++)
                {
                    ret.push_back({intervals[i][0],intervals[i][1]});
                }
                break;
            }
            
            //如果运行到这里，说明 有区间重叠
            int curmin = min(intervals[i][0],newInterval[0]);
            int curmax = newInterval[1];
            while(i < intervals.size() && newInterval[1] >= intervals[i][0])
            {
                curmax = max(curmax,intervals[i][1]);
                i++;
            }
            ret.push_back({curmin,curmax});

            for(;i<intervals.size(); i++)
            {
                ret.push_back({intervals[i][0],intervals[i][1]});
            }
            break;
            
        }
        //如果插入区间是最大的，那么直接加到最后
        if(intervals[intervals.size()-1][1]<newInterval[0])
        {
            ret.push_back({newInterval[0],newInterval[1]});
        }
        return ret;
    }
};
```