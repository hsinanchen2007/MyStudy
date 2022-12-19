由题目给的两个提示可以给出以下方法。
先给所有人排个序，从矮到高排，同高度的从前面比他高的人多的到人少的排。
遍历这个序列，对每个人，若排他前面不比他矮的人有k个，则他所排的位置前面有k个空位，即有k个还没排人的位子。
```
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		vector<int> tmp = { -1,-1 };
		vector<vector<int>> res(people.size(), tmp);
		sort(people.begin(), people.end(), [](const vector<int> A, const vector<int>B) {
			if (A[0] < B[0] || (A[0] == B[0] && A[1] > B[1]))
				return true;
			return false;
			});
		for (int i = 0; i < people.size(); i++) {
			int count = 0;
			for (int j = 0; j < res.size(); j++) {
				if (res[j] == tmp)
					count++;
				if (count == people[i][1] + 1) {
					res[j] = people[i];
					break;
				}
			}
			
		}
		return res;
	}
};
```
