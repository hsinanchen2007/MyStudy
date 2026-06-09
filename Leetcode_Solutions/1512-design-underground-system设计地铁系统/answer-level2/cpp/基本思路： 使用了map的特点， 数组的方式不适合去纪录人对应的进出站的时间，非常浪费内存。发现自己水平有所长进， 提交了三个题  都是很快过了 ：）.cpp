### 解题思路
此处撰写解题思路

### 代码

```cpp
class UndergroundSystem {
    unordered_map<string, unordered_map<int, int>> listMap;

public:
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {  // id means people
        listMap[stationName][id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        listMap[stationName][id] = t;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double average = 0;
        int cnt = 0;
        for (auto &endEle : listMap[endStation]) {
            auto startEle = listMap[startStation].find(endEle.first);
            if (startEle != listMap[startStation].end()) {
                cnt++;
                average += endEle.second - startEle->second;
            }
        }
        cout << average << ":" << cnt << endl;
        return average/cnt;
    }
};

```