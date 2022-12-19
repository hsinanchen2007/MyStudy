把进入和离开的时间各自先按照站名，再按照乘客ID进行索引。这样在查询时，就可以快速定位到所有在指定站点进入和离开的所有乘客，及其时间。求时间差的平均值即可。

考虑到可能出现某一乘客多次进入和离开同一个站点的情形，保险起见，用一个类数组的数据结构存储下每个乘客的所有进入/离开时间。

参考代码：

```c++
class UndergroundSystem {
    unordered_map<string, unordered_map<int, vector<int>>> enter;
    unordered_map<string, unordered_map<int, vector<int>>> exit;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if (enter.find(stationName) == enter.end()) {
            enter[stationName] = unordered_map<int, vector<int>>();
        }
        if (enter[stationName].find(id) == enter[stationName].end()) {
            enter[stationName][id] = vector<int>({t});
        } else {
            enter[stationName][id].push_back(t);
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        if (exit.find(stationName) == exit.end()) {
            exit[stationName] = unordered_map<int, vector<int>>();
        }
        if (exit[stationName].find(id) == exit[stationName].end()) {
            exit[stationName][id] = vector<int>({t});
        } else {
            exit[stationName][id].push_back(t);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        double total = 0;
        int cnt = 0;
        
        for (const auto & r : enter[startStation]) {
            int id = r.first;
            if (exit[endStation].find(id) != exit[endStation].end()) {
                auto v1 = r.second;
                auto v2 = exit[endStation][id];
                const int n = min(v1.size(), v2.size());
                for (int i = 0; i < n; i++) {
                    total += (v2[i] - v1[i]);
                    cnt++;
                }
            }
        }
        
        return total / cnt;
    }
};
```

计算过程还可以进一步优化：例如直接在乘客离开站点时就计算时间差。甚至你还可以对车站对进行索引，动态更新平均值，这样查询就几乎只要常数的时间。