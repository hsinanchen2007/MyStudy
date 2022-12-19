### 解题思路
思路很简单，将原向量种的每一个数放到数轴上，并且区间左边的附上一个-（在pair里表示为second=0)，区间右边的附加一个负号（在pair里表示为1
### 代码

```cpp
class Solution {
public:
    static bool mycmp(pair<int,bool>a,pair<int,bool>b){
    if(a.first==b.first)
        return a.second<b.second;
    else
        return a.first<b.first;
}
    vector<vector<int> > ans_intervals;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, bool> > axis;
        int height = intervals.size();
        for(int i=0;i<height;i++){
            int num = intervals[i][0];
            bool sign = 0;
            axis.push_back(pair<int,bool>(num, sign));
            num = intervals[i][1];
            sign = 1;
            axis.push_back(pair<int,bool>(num, sign));
        }
        sort(axis.begin(),axis.end(),mycmp);
        int interval_begin_index = 0;
        int left_count = 1;
        int right_count = 0;
        int i = 1;
        while(i < axis.size()){
            if(axis[i].second==0)
                left_count++;
            else{
                right_count++;
                if(right_count>=left_count){
                    vector<int> ans_interval;
                    ans_interval.push_back(axis[interval_begin_index].first);
                    ans_interval.push_back(axis[i].first);
                    ans_intervals.push_back(ans_interval);
                    i++;
                    interval_begin_index = i;
                    left_count = 1;
                    right_count = 0;
                }
            }
            i++;
        }
        
    return this->ans_intervals;
    }
};

```