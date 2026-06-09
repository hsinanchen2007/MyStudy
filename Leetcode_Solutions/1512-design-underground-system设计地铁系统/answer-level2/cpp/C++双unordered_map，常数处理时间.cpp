使用两个unordered_map来处理数据，一个用以存储人员id与起点终点等的对应关系，一个用来处理一段行程与每一个到达时间的关系
每次有乘客上车更新stationmap，每次有乘客下车更新timemap，最终查询时间为O(m),m为该旅途的人数
```c++
class UndergroundSystem {
public:
    typedef struct Underground{
        string startStation;
        int startTime = 0;
        string endStation;
        int endTime = 0;
    }Underground;
        
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        Underground temp;
        temp.startTime = t;
        temp.startStation = stationName;
        stationmap[id] = temp;
    }
    
    void checkOut(int id, string stationName, int t) {
        Underground temp = stationmap[id];
        temp.endStation = stationName;
        temp.endTime = t;
        stationmap[id] = temp;
        string station = temp.startStation + temp.endStation;
        int time = temp.endTime - temp.startTime;
        if(timemap.find(station) != timemap.end()){
            vector timeVec = timemap[station];
            timeVec.push_back(time);
            timemap[station] = timeVec;
        }
        else{
            vector<int> myVec;
            myVec.push_back(time);
            timemap[station] = myVec;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string station = startStation + endStation;
        if(timemap.find(station) != timemap.end()){
            vector timeVec = timemap[station];
            int all = 0;
            for(int i = 0;  i < timeVec.size(); ++i){
                all += timeVec[i];
            }
            return (double(all)/timeVec.size());
        }
        else
            return 0.0;
    }
private:
    unordered_map<int, Underground> stationmap;
    unordered_map<string, vector<int>> timemap;
};

```