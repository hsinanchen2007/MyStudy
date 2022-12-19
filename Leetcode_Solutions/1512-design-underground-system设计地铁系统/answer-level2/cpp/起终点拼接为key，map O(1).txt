# 思路
上车记录，下车算数。
ps: 就是在下车的时候 计算一下， 这两个站 之间 消耗了多长时间，用map 存一下

```
class UndergroundSystem {
public:
    class Trip {
    public:
        Trip() {}
        string ci; //起始站名
        int ti = 0; //上车时间
    };
    
    map<int, Trip*> tm; // 用户的行程，id是key
    map<string, int> summ; //起终点的总时长
    map<string, int> cntm; //起终点的人数
    UndergroundSystem() {
    }
    ~UndergroundSystem() {
        for (auto& kv : tm) { //释放空间
            delete kv.second;
            kv.second = nullptr;
        }
    }
    void checkIn(int id, string name, int t) {
        Trip* pt = new Trip(); 
        pt->ci = name;
        pt->ti = t;
        tm.insert({id, pt}); //记录一个用户
    }
    
    void checkOut(int id, string name, int t) {
        string s = tm[id]->ci + name;  //起终点名字拼起来作为key
        summ[s] += t - tm[id]->ti; //加总时长
        cntm[s]++; //加人数
        
        delete tm[id]; //释放空间
        tm[id] = nullptr;
        tm.erase(id);
    }
    
    double getAverageTime(string a, string b) {
        string s = a + b;
        return summ[s] * 1.0 / cntm[s];  //时长/人数
    }
};
```