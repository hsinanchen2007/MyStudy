``` c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //vector<vector<int>> res;
        if(intervals.empty())return vector<vector<int>>();
        sort(intervals.begin(),intervals.end(),
            [](auto& v1,auto& v2){return v1[0]<v2[0];});
        
        //找第一个区域的左区间大于现在的右区间
        //若小于，则合并
        int i = 1;
        while(i<intervals.size()){
            if(intervals[i][0] <= intervals[i-1][1]){
                intervals[i-1][1] = max(intervals[i][1],intervals[i-1][1]);
                intervals.erase(intervals.begin()+i);
            }else{
                i++;
            }

        }
            

        return intervals;
        }
        
            
};
```