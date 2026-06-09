### 解题思路
主要是两个map， key都是起始站+结束站，一个sum的map的value记录时间累计值，另一个time的map记录乘车次数
另外有一个辅助的map，记录checkin时的临时信息。
checkIn的时候，记录这个用户的起始站，和进站时间；
每次checkOut的时候，可以通过查询该用户的进站时间，计算出乘车时间，累加进sum里，sumMap不关注ID，另外把次数也累计一次。
getAverageTime的时候，查询起始站的sum/time就是平均时间了。

这道题，选择不同的数据结构，效率会差的比较多。
### 代码

```cpp
class UndergroundSystem {
public:
    UndergroundSystem() {      
    } 
    void checkIn(int id, string stationName, int t) {
        startArray[id].first = stationName;
        startArray[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string startName = startArray[id].first;
        sumMap[startName + stationName] += t - startArray[id].second;
        timeMap[startName + stationName]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + endStation;
        return sumMap[key] * 1.0 / timeMap[key];
    }
private:
    map<int, pair<string, int>> startArray;
    map<string, int> sumMap;
    map<string, int> timeMap;
};
/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
```