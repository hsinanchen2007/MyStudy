```cpp
class Solution {
public:
    vector<int> getDay(string str){
        vector<int> res;
        res.push_back((str[0]-'0')*1000+(str[1]-'0')*100+(str[2]-'0')*10+(str[3]-'0'));
        res.push_back((str[5]-'0')*10+(str[6]-'0'));
        res.push_back((str[8]-'0')*10+(str[9]-'0'));
        return res;
    }
    int dayOfYear(string date) {
        vector<int> feirunnian={0,31,59,90,120,151,181,212,243,273,304,334};
        vector<int> runnian={0,31,60,91,121,152,182,213,244,274,305,335};
        vector<int> days=getDay(date);
        if((days[0]%4==0&&days[0]%100!=0)||(days[0]%400==0)){
            return runnian[days[1]-1]+days[2];
        }else{
            return feirunnian[days[1]-1]+days[2];
        }
        return 0;
    }
};
```