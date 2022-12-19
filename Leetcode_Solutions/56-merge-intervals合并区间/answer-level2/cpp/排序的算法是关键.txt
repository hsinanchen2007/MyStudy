### 解题思路
开始我尝试自己写的比较函数，发现无法通过，卡在特别长的一个用例上，报错`runtime error: reference binding to null pointer of type 'value_type' (stl_vector.h)`。不知道有没有大佬解答一下什么原因。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(intervals.empty()||n<=1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]>res.back()[1]){
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0]<=res.back()[1]<intervals[i][1]{
                res.back()[1] = intervals[i][1];
            }
        }
        return res;
    }
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]<b[0]||(a[0]==b[0]&&a[1]<=b[1])){
            return true;
        }
        else{
            return false;
        }
    }
};
```