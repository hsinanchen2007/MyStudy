### 思路
1. 使用 `checkRecord` 根据 `id` 来保存上车 **车站名字** 和 **时间**
2. 在下车车站，把乘车时间计算出来，按两个 **车站名字** 保存起来，同时还要保存 **乘车次数**
3. 取得平均时间时，只需要查询两个车站，得到总时间，和总次数

### 答题
```C++ []
class UndergroundSystem {
public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        checkRecord[id] = { stationName, t };
    }

    void checkOut(int id, string stationName, int t) {
        string name = getStationName(checkRecord[id].first, stationName);
        t -= checkRecord[id].second;
        count[name].first += (double)t;
        count[name].second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        string name = getStationName(startStation, endStation);
        double ans = count[name].first / (double)count[name].second;
        return ans;
    }

private:
    string getStationName(string startStation, string endStation)
    {
        return startStation + endStation;
    }

    unordered_map<int, pair<string, int>> checkRecord;
    unordered_map<string, pair<double, int>> count;
};
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

