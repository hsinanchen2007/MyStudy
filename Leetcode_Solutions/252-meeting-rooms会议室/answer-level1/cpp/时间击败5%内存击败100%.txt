### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        unordered_set<int> timehash;
        for(int i = 0; i < intervals.size(); i++){
            for(int j = intervals[i][0]; j < intervals[i][1]; j++){
                if(timehash.count(j) > 0){
                    return false;
                }else{
                    timehash.insert(j);
                }
            }
        }
        return true;
    }
};
```