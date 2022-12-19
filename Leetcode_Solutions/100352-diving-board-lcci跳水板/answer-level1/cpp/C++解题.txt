提交前看看数据边界值，`k == 0`， `shorter == longer`等情况分开讨论就可以

```c++
class Solution {
public:
	vector<int> divingBoard(int shorter, int longer, int k) {
		if (k == 0)
			return {};
		vector<int> ans;
		if (shorter == longer)
			ans.push_back(shorter * k);
		else {
			for (int i = 0; i <= k; i++) {
				ans.push_back(longer * i + shorter * (k - i));
			}
		}
		return ans;
	}
};
```