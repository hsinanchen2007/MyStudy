```
    unordered_map<string,unordered_map<string,int>> resTime;//保存两个车站之间的总时间
    unordered_map<string,unordered_map<string,int>> resCnt;//保存两个车站之间的总人数
    unordered_map<int,pair<string,int>> a;//人的id所对应的起始车站以及上车时间
    UndergroundSystem() {}
    void checkIn(int id, string s, int t) {
        a[id] = {s,t};
    }
    void checkOut(int id, string e, int te) {
        auto [s,ts] = a[id];//获取起点以及上车时间
        resTime[s][e] += te - ts;//加上该人的时间
        resCnt[s][e]++;
    }
    double getAverageTime(string s, string e) {
        return resTime[s][e]*1.0/resCnt[s][e]; 
    }
```
