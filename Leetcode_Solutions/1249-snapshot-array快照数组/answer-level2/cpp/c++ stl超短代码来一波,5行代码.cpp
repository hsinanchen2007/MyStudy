同志们，stl赶紧用熟，你看，用熟的话周竞赛一分钟一道题，我日！！！！！！！！！！！！！！！！！
```

class SnapshotArray {
public:
	unordered_map<int,map<int,int,greater<int>>>record;
	int snap_times=0;
	SnapshotArray(int length) {
	}

	void set(int index, int val) {
		record[index][snap_times] =val;
	}

	int snap() {
		return snap_times++;
	}

	int get(int index, int snap_id) {
        return record[index].lower_bound(snap_id)->second;
	}
};
```
