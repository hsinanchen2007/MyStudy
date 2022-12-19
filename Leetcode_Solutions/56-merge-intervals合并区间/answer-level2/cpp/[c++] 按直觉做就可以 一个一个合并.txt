### 解题思路
 按左区间由小到大排序，如果：
前一个区间最大值>=当前区间最小值，则合并区间
否则将上个区间加入结果集

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        if(intervals.empty())
            return res;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[0]<b[0];
        });
        for(int i=1;i<n;i++){
            if(intervals[i-1][1]>=intervals[i][0])
            { intervals[i][1]  = max(intervals[i-1][1],intervals[i][1]);
            intervals[i][0] = intervals[i-1][0];
            }
            else {
                res.push_back(intervals[i-1]);
            }
            
         
        }
        res.push_back(intervals[n-1]);
        return res;
    }
};
```