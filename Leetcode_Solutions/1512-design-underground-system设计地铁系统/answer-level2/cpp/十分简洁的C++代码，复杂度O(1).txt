```c++
class UndergroundSystem {
public:
	//第一个map的key为起始站(string)，
	//第二个map的key为终点站，val的第一个int为所有 以此为起终点 的时间累计，第二个int为 以此为起终点 的次数
	unordered_map<string, unordered_map<string, pair<int, int> > > mp;

	//key为乘客id，val的string为起始站，int为到达起始站的时刻
	unordered_map<int, pair<string, int> > mmp;
	UndergroundSystem() {}

	void checkIn(int id, string stationName, int t) {
		mmp[id].first = stationName;
		mmp[id].second = t;
	}

	void checkOut(int id, string stationName, int t) {
		int time = t - mmp[id].second;
		string startStation = mmp[id].first;
		mp[startStation][stationName].first += time;
		mp[startStation][stationName].second++;
	}

	double getAverageTime(string startStation, string endStation) {
		auto c = mp[startStation][endStation];
		return c.first * 1.0 / c.second;
	}
};
```
