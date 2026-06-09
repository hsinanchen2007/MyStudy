### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(!intervals.size()) return true;//会议时间为空，没有会议不存在延误
        sort(intervals.begin(), intervals.end(), less<vector<int>>());//将会议开始时间排序
        int pos = 0;//第一个指针
        for(int i = 1; i < intervals.size(); i++){//i第二个指针
            if(intervals[pos][1] <= intervals[i][0]){//暂时指向的会议无冲突时，换到下一个
                pos++;
            }else{
                return false;
            }
        }
        return true;
    }
};
```