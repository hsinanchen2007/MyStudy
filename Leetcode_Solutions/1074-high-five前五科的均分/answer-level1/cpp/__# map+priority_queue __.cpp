**# map+priority_queue **
小白刷题记录
1. map映射id与score（map自动根据key排序）
2. priority_queue的 (构建size为5的小顶堆)
```
class Solution {
public:
	vector<vector<int>> highFive(vector<vector<int>>& items) {
		vector<vector<int>> res;
		map<int, priority_queue<int,vector<int>,greater<int>>> data;
		for (int i = 0; i < items.size(); i++) {
			if (data.count(items[i][0])==0) {
				priority_queue<int, vector<int>, greater<int>> q;
				q.push(items[i][1]);
				data.insert(map<int, priority_queue<int,vector<int>,greater<int>>>::value_type(items[i][0], q));
			}
			else {
				if (data[items[i][0]].size() < 5) {
					data[items[i][0]].push(items[i][1]);
				}
				else {
					if (items[i][1] > data[items[i][0]].top()) {
						data[items[i][0]].pop();
						data[items[i][0]].push(items[i][1]);
					}
				}
			}

		}
		for (map<int, priority_queue<int, vector<int>, greater<int>>>::iterator it = data.begin(); it!=data.end(); it++) {
			int ave = 0;
			for (int i = 0; i < 5; i++) {
				ave += it->second.top();
				it->second.pop();
			}
            ave/=5;
            vector<int> temp;
            temp.push_back(it->first);
            temp.push_back(ave);
			res.push_back(temp);
		}
		return res;
	}
};
```
