### 解题思路
先根据左边界排序，之后双指针考虑zero的右边界是否大于i的左边界，大则重复，此时zero选取右边界更小的，保证影响最小

### 代码

```cpp
class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>&hl,const vector<int>&hr){
            return hl.at(0)<hr.at(0);

        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp());
        int count=0,zero=0; 
        for(int i=1;i<intervals.size();i++){
            if(intervals.at(zero).at(1)>intervals.at(i).at(0)) {
                count++;
                if(intervals.at(zero).at(1)>intervals.at(i).at(1)) zero=i;
            }
            else zero=i;
        }
        return count;
    }
};
```