### 解题思路
先排序，以第一个区间为起始点，right大于等于第二个区间的left，则比较两个区间的最大右端，


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> res;
       if(intervals.empty())  return res;
       sort(intervals.begin(),intervals.end());
       int left=intervals[0][0];
        int right=intervals[0][1];
        int i=1;
       for(;i<intervals.size();i++)
       {
           if(right>=intervals[i][0])
           {
               right=max(intervals[i][1],right);
           }
           else
           {
               res.push_back({left,right});
                left=intervals[i][0];
                right=intervals[i][1];
           }
       }  
       res.push_back({left,right});
       return res;
    }
};
```