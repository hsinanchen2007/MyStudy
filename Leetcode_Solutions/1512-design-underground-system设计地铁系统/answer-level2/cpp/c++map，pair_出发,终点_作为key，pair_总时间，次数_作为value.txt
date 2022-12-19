双百，思路：pair<出发,终点>作为key，pair<总时间，次数>作为value。但出了个问题：最后return为什么要返回1.0*，不然通过不了最后一个用例，截取的小数位数有问题。
```
struct System{
int id;
string stationName;
double t;
};
class UndergroundSystem {
private:
vector<System> a;
map<pair<string,string>,pair<int,int>> aver;//记录<始发站，终点站>的<总时间，次数>，博客unordered_map似乎不支持pair作value
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        System x;
        x.id=id;x.stationName=stationName;x.t=t;
        a.push_back(x);
    }
    
    void checkOut(int id, string stationName, int t) {
        System x; vector<System>::iterator it;
        //x->id=id;x->stationName=stationName;x->t=t;
        for(it=a.begin();it!=a.end();it++)
        {
            if((*it).id==id)
            {
                break;
            }
        }
        int delta=t-(*it).t;
        auto key=make_pair((*it).stationName,stationName);
        auto val=aver[key];
        val.first+=delta; val.second++;
        aver[key]=val;
        a.erase(it);
    }
    
    double getAverageTime(string startStation, string endStation) {
       auto key=make_pair(startStation,endStation);
       return 1.0*aver[key].first/aver[key].second;
    }
};
```
