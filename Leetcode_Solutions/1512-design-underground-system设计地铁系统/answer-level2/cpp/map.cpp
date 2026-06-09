- map1 记录起点，到终点后，更新另一个map2的信息，map1删除该条信息
```cpp
class UndergroundSystem {
	map<vector<string>,vector<int>> station_time_n;//2个string（起点，终点）；2个int（总时间，人数）
	map<int, pair<string,int>> id_startStation;// 乘客id；（起点，出发时刻）
	vector<string> s;
public:
    UndergroundSystem() { }
    
    void checkIn(int id, string stationName, int t) {
        id_startStation.insert({id,make_pair(stationName,t)});// 乘客id；（起点，出发时刻）
    }
    
    void checkOut(int id, string stationName, int t) {
    	s = {id_startStation[id].first, stationName};//起点，终点
    	if(!station_time_n.count(s))
        	station_time_n.insert({s,{t-id_startStation[id].second,1}});
        else
        {
        	station_time_n[s][0] += t-id_startStation[id].second;
        	station_time_n[s][1] += 1;
        }
       id_startStation.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
    	s = {startStation, endStation};
        return station_time_n[s][0]/double(station_time_n[s][1]);
    }
};
```
![在这里插入图片描述](https://pic.leetcode-cn.com/d592692657ee59b22e77834576fd65142779402e781b8c35ac0e544c26669f2e.png)