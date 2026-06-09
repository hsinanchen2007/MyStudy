### 解题思路
主要是把时间戳转成数字，放到map中，自动排序

### 代码

```cpp
class LogSystem {
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        timestamp.erase(remove(timestamp.begin(), timestamp.end(), ':'), timestamp.end());
        long long logTime = stoll(timestamp);
        logStore[logTime] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        pair<long long, long long> seTime;
        seTime = GetStartEndTimeByGra(s, e, gra);

        vector<int> result;
        auto startIt = logStore.lower_bound(seTime.first); 
        while (startIt->first < seTime.second && startIt != logStore.end()) {
            result.push_back(startIt->second);
            ++startIt;
        }

        return result;
    }
private:
    map<long long, int> logStore;

    pair<long long, long long> GetStartEndTimeByGra(string s, string e, string gra)
    {
        pair<long long, long long> time = {0, 0};

        s.erase(remove(s.begin(), s.end(), ':'), s.end());
        e.erase(remove(e.begin(), e.end(), ':'), e.end());

        if (gra == "Year") {
            s.replace(4, 10, "0000000000");
            e.replace(4, 10, "0000000000");
            time.first = stoll(s);
            time.second = stoll(e) + 10000000000;
            return time;
        } else if (gra == "Month") {
            s.replace(6, 8, "00000000");
            e.replace(6, 8, "00000000");
            time.first = stoll(s);
            time.second = stoll(e) + 100000000;
            return time;
        } else if (gra == "Day") {
            s.replace(8, 6, "000000");
            e.replace(8, 6, "000000");
            time.first = stoll(s);
            time.second = stoll(e) + 1000000;
            return time;
        } else if (gra == "Hour") {
            s.replace(10, 4, "0000");
            e.replace(10, 4, "0000");
            time.first = stoll(s);
            time.second = stoll(e) + 10000;
            return time;
        } else if (gra == "Minute") {
            s.replace(12, 2, "00");
            e.replace(12, 2, "00");
            time.first = stoll(s);
            time.second = stoll(e) + 100;
            return time;  
        } else if (gra == "Second") {
            time.first = stoll(s);
            time.second = stoll(e) + 1;
            return time;  
        } else {
            return time;
        }
    }
};


/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */
```