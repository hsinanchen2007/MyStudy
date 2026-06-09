贪心，先每个人安排到费用最低的城市。必定有城市去该城市的人数大于等于n，我们贪心的认为，只有将人数多的城市的人转移到人数少的城市是总费用最低的，证明如下：
若两城市有交换人员，那么将每对交换的人员都改成不交换将得到更少的总费用。因此两城市不会有人员交换，只能人数多的城市的人到人数少的城市。
那么调过去哪些人呢？当然是调由调换导致的增加的费用最少的人了。
代码如下，由于是C++不是python，导致有地方操作十分繁琐，增加了map之类的结构来完成某些数据的记录。
```
class Solution {
public:
	static bool cmp(const pair<int, int>& a, const pair<int, int>& b){
		return a.second < b.second;
	}

	int twoCitySchedCost(vector<vector<int>>& costs) {
		map<int, int> flag;
		int sum = 0;
		for (int i = 0; i < costs.size(); i++){
			flag[i] = costs[i][0] - costs[i][1];
		}
		vector<pair<int, int>> vec(flag.begin(), flag.end());
		sort(vec.begin(), vec.end(), cmp);
		for (int i = 0; i < vec.size()/2; i++){
			if (vec[i].second>0){
				vec[i].second = -vec[i].second;
			}
		}
		for (int i = vec.size() / 2; i<vec.size(); i++){
			if (vec[i].second < 0){
				vec[i].second = -vec[i].second;
			}
		}
		for (int i = 0; i < vec.size(); i++){
			if (vec[i].second < 0)
				sum += costs[vec[i].first][0];
			else
				sum += costs[vec[i].first][1];
		}
		return sum;
	}
};
```
