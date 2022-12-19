### 解题思路
暴力解决即可
保存每个id的上车信息
存储每对上下车对的耗费时间和经过的人的个数

### 代码

```cpp
class UndergroundSystem {
private:
    struct flowrate{
        double time;
        int n;
    };
    struct idinfo{
        string name;
        int time;
    };
    unordered_map<string, flowrate>mp_average;
    unordered_map<int, idinfo>mp_time; 
public:
    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        mp_time[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        string travel = mp_time[id].name + stationName;
        if(mp_average.count(travel) == 0){
            mp_average[travel].time = 0;
            mp_average[travel].n = 0;
        }
        mp_average[travel].time += (t - mp_time[id].time);
        ++mp_average[travel].n;
    }

    double getAverageTime(string startStation, string endStation) {
        return mp_average[startStation + endStation].time / mp_average[startStation + endStation].n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

```