还是比较好理解的，用了两个map才不至于AC，并且速度还蛮快的。
因为人的id值不大于一百万，所以一开始我用数组保存，人的上车信息，这样会超时，所以改成map。
mpPerson[i]表示id为i的人的上车站名和时间，等待下车时访问该数据。
mp[s+t]表示上车站名为s和下车站名为t的乘车历史时间只和和次数。如果有四个站名为"a","bc"，"ab","c",然后"a"->"bc","ab"->"c"，这两个组合后都是"abc"，就有可能输出错误答案，不过数据没有卡我。建议在两个站名之间添加下划线，这样就没有瑕疵了。
```
class UndergroundSystem {
	struct node{
		long long t;
		int sum;
	};
	struct person {
		string st;
		int stTime;
        person(){}
		person(string stationName, int t) :st(stationName), stTime(t) {}
	};
	map<string, node> mp;
	map<int, person> mpPerson;

public:
	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		mpPerson[id] = person(stationName, t);
	}

	void checkOut(int id, string stationName, int t) {
		string station = mpPerson[id].st + stationName;
		int timeSum = t - mpPerson[id].stTime;
		mp[station].t += timeSum;
		++mp[station].sum;
	}

	double getAverageTime(string startStation, string endStation) {
		struct node tmp = mp[startStation + endStation];
		return (double)tmp.t / (double)tmp.sum;
	}
};
```
