# 5370. 设计地铁系统
可以使用 STL 来存储数据，高效实现地铁管理系统🐶。
数据容器的设计可以参见注释。

```cpp
class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    //所有完成的通行记录
    //key.first 为上车站，key.second 为下车站
    //value.first 为累计用时，value.second 为完成的通行次数。
    map<pair<string, string>, pair<int64_t, int>> data;
    //缓存乘客尚未完成的通行记录
    //key 为 乘客ID
    //value.first 为乘客上车站，value.second 为出发时间。
    //乘车下车后，记录应从该容器中移除。
    map<int, pair<string, int>> passenger;
    void checkIn(int id, string stationName, int t) {
        passenger[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = passenger.find(id);
        data[make_pair(it->second.first, stationName)].first += t - it->second.second;
        data[make_pair(it->second.first, stationName)].second ++;
        passenger.erase(it);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto it = data.find(make_pair(startStation, endStation));
        return double(it->second.first)/(it->second.second);
    }
};
```
 # 扫码关注 快乐加倍
![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/c76daf1deeba4b94c92858e4d52e2f6b0b5b151a2e6d09e0c237357a07210aa2-qrcode_for_gh_6e5f8557b1f8_258.jpg)
