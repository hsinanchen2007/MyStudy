* 两个map
* map<string, map<int, int>> 保存入栈记录，对应的信息是 map<站名stationName，map<用户id，进站时间t>>
* map<string, map<int, int>> 保存出栈的记录，对应的信息和上述一样

```C++

class UndergroundSystem {
public:
    UndergroundSystem() = default;
    void checkIn(int id, string stationName, int t);
    void checkOut(int id, string stationName, int t);
    double getAverageTime(string startStation, string endStation);
private:
    map<string, map<int, int>> checkInRecord;
    map<string, map<int, int>> checkOutRecord;
};

void UndergroundSystem::checkIn(int id, string stationName, int t) {
    checkInRecord[stationName][id] = t;
}

void UndergroundSystem::checkOut(int id, string stationName, int t) {
    checkOutRecord[stationName][id] = t;
}

double UndergroundSystem::getAverageTime(string startStation, string endStation) {
    int total = 0;
    int cnt = 0;
    map<int, int> &record = checkOutRecord[endStation];
    for (auto &p : record) {
        if (checkInRecord[startStation].count(p.first)) {
            total += p.second - checkInRecord[startStation][p.first];
            cnt++;
        }
    }
    if (cnt == 0)
        return 0.0;
    return double(total) / (double)cnt;
}

```
