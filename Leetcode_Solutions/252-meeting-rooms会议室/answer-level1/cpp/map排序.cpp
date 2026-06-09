使用map有序性，根据会议开始时间排序
条件：前一次会议结束时间<后一次会议开始时间
O（2n+nlogn）
```
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        map<int,int> data;
        for(auto i:intervals){
            if(data.count(i[0])==0)
                data.insert(map<int,int>::value_type(i[0],i[1]));
            else{
                return false;
            }
        }
        for(map<int,int>::iterator it=data.begin();it!=data.end();){
            if(it->second > (++it)->first){
                if(it!=data.end())
                    return false;
                else
                    break;
            }
        }
        return true;
    }
};
```
