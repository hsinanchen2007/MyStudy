
### 代码

```cpp
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> passenger;//<乘客id, <上车站, 上车时间>>
    unordered_map<string, pair<int, int>> time;//<"上车站,下车站", <总用时, 总人次>>
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        passenger[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string s2e = passenger[id].first + ',' + stationName;
        int time_spend = t - passenger[id].second;
        if(time.find(s2e) == time.end())
            time[s2e] = make_pair(time_spend, 1);
        else{
            time[s2e].first += time_spend;
            time[s2e].second += 1;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s2e = startStation + ',' + endStation;
        double ans =  double(time[s2e].first) / time[s2e].second;
        return ans;
    }
};
```