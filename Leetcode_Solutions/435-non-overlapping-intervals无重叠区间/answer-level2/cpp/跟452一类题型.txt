### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;
        int res=0;  
        sort(intervals.begin(),intervals.end());
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(end<=intervals[i][0]){
                end=intervals[i][1];
            } else {
                end=min(end,intervals[i][1]);
                  res++;
            }
        }
        return res;
    }
};
```