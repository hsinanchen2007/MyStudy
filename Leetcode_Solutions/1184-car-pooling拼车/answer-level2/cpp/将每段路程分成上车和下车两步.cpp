将每段路程分成上车和下车两个步骤，位置pos处上车k人，记作（k,pos），位置pos处下车k人，记作（-k,pos）
对所有步骤进行排序，pos小的排在前面，pos相等的，下车的排前面即记录中第一个数据小的排前面。
然后遍历所有步骤，记录每个步骤后车上的人数，如果超过capacity就返回false。
```C++ []
class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		int total = 0;
		vector<vector<int>> people;
		for (int i = 0; i < trips.size(); i++) {
			vector<int> tmp1 = { trips[i][0],trips[i][1] };
			vector<int> tmp2 = { -trips[i][0],trips[i][2] };
			people.push_back(tmp1);
			people.push_back(tmp2);
		}
		sort(people.begin(), people.end(), [](const vector<int> A, const vector<int> B) {
			if (A[1] < B[1] || (A[1] == B[1] && A[0] < B[0]))
				return true;
			return false;
			});
		for (int i = 0; i < people.size(); i++) {
			total += people[i][0];
			if (total > capacity) {
				return false;
			}
		}
		return true;
	}
};
```
