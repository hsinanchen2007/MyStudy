```
struct pass
{
    int ID;
    string sat;
    int st=0;
};
class UndergroundSystem {
private:
    
    map<int,pass> mp2;
    map<pair<string,string>,pair<int,double>> mp;    
public:
    UndergroundSystem() {
        mp.clear();
        mp2.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        pass p;
        p.ID=id;p.sat=stationName;p.st=t;
        mp2[id]=p;
    }
    
    void checkOut(int id, string stationName, int t) {
        pass i=mp2[id];
        int o=0;double avr=0;
        o=++mp[make_pair(i.sat,stationName)].first;
        avr=mp[make_pair(i.sat,stationName)].second;
        avr=(avr*(o-1)+t-i.st)/o;
        mp[make_pair(i.sat,stationName)].second=avr;
                           
    }
    
    double getAverageTime(string startStation, string endStation) {
        return mp[make_pair(startStation,endStation)].second;
    }
};
```
