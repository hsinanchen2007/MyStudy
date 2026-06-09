### 解题思路
官方思路，C++解法

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> result,temp;
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]<newInterval[0]) result.push_back(intervals[i]);
            else temp.push_back(intervals[i]);
        }
        if(result.size()==0 || result[result.size()-1][1]<newInterval[0])
            result.push_back(newInterval);
        else
            result[result.size()-1][1]=max( result[result.size()-1][1],newInterval[1]);
        if(temp.size()==0) return result;
        for(int i=0;i<temp.size();i++)
        {
            if(result[result.size()-1][1]<temp[i][0]) result.push_back(temp[i]);
            else
            {
                result[result.size()-1][1]=max(result[result.size()-1][1],temp[i][1]);
            }
        }
        return result;
    }
};
```