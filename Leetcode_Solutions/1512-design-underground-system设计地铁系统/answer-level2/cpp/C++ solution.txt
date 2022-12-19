### 解题思路
一个人可能有多次相同的进出站记录。不能做进出站和Id的映射。

### 代码

```cpp
typedef struct {
    string in_station, out_station="";
    int in_time, out_time=0;
}inf;
class UndergroundSystem {
public:
    UndergroundSystem() {
        mp.clear();
        tot_num.clear();
        tot_time.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        inf tmp;
        tmp.in_station = stationName;
        tmp.in_time = t;
        mp[id] = tmp;
    }
    
    void checkOut(int id, string stationName, int t) {
        mp[id].out_station = stationName;
        mp[id].out_time = t;
        tot_time[make_pair(mp[id].in_station, stationName)] += (t-mp[id].in_time);
        tot_num[make_pair(mp[id].in_station, stationName)]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        int tot = tot_time[make_pair(startStation, endStation)];
        int num = tot_num[make_pair(startStation, endStation)];
        return tot * 1.0 / num;
    }
private:
    map<int, inf> mp;
    map<pair<string, string>, int> tot_time;
    map<pair<string, string>, int> tot_num;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
```