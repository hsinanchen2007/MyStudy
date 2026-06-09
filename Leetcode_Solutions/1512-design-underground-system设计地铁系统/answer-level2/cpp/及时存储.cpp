### 解题思路
此处撰写解题思路

### 代码

```cpp
class UndergroundSystem {
private:
    unordered_map<int,pair<string,int>> st;
    unordered_map<string,pair<double,int>> m;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        st[id]={stationName,t};
        
    }
    
    void checkOut(int id, string stationName, int t) {
        string sname = st[id].first;
        sname+=stationName;
        if(m.find(sname)==m.end()){
            m[sname].first=(t-st[id].second)*1.0;
            m[sname].second=1;
        }    
        else{
            m[sname].first+=(t-st[id].second)*1.0;
            m[sname].second++;
        } 
    }
    
    double getAverageTime(string startStation, string endStation) {
        return m[startStation+endStation].first/m[startStation+endStation].second;
        
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