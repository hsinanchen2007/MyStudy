```
class UndergroundSystem {
public:
    map< string, map<string, pair<int, int>* > > umap;
    map< int,pair<int, string>* > goin;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        pair<int, string> *ts = new pair<int, string>(t, stationName);
        goin[id] = ts;
    }
    
    void checkOut(int id, string stationName, int t) {
        if (!umap[goin[id]->second][stationName])
            umap[goin[id]->second][stationName] = new pair<int, int>(0,0);
        umap[goin[id]->second][stationName]->first += t-goin[id]->first;
        umap[goin[id]->second][stationName]->second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)umap[startStation][endStation]->first / umap[startStation][endStation]->second;
    }
};
```
